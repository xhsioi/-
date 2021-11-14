#include <cstdlib>
#include <iostream>
#include <string>
int flag=0;
using namespace std;
//-5*(-2+9*6)-2+3*5=-247

template <class T>
class stack {
private:
    int top; //栈顶
    int maxtop; //最大的栈顶值
    T* st; //堆栈元素数组
public:
    stack(int maxstacksize = 10)
    {
        maxtop = maxstacksize - 1;
        st = new T[maxstacksize];
        top = -1;
    }
    ~stack()
    {
        delete[] st;
    }
    bool isfull()
    {
        return top == maxtop;
    }
    bool isempty()
    {
        return top == -1;
    }
    bool add(const T& x)
    {
        if (isfull()) {
            cout << "no memory" << endl;
            return false;
        }
        top++;
        st[top] = x;
        return true;
    }
    T del()
    {
        if (isempty()) {
            cerr << "no element" << endl;
        }
        T x;
        x = st[top];
        top--;
        return x;
    }
    T returntop()
    {
        return st[top];
    }
    void clear()
    {
        top = -1;
    }
};

class Calculator {
public:
    string infix; //中缀表达式
    string postfix; //后缀表达式
    stack<double> poststack; //后缀栈
    Calculator(string str);
    ~Calculator()
    {
        poststack.clear();
    }
    void infix_to_suffix(); //1.4-e  将中缀表达式转换为后缀表达
    int inStack(char ch); //栈内优先级
    int outStack(char ch); //栈外优先级数
    void cal_suffix(); //计算中缀表达式的值
    void print();
    bool Get_operands(double& left, double& right);
    bool isNumber(char ch);
    double returnnum(char *c,int n); //返回字符对应的数
    float toNum(char num_ch); //数值型字符转换成数字
    void cal(char ch); //根据操作符 去栈中去取两个元素计算
};
Calculator::Calculator(string str)
{
    infix = str;
}

string format(string str) {//将表达式中的负数转化成0-正数的形式					
	for (int i = 0; i < str.length(); i++)	
		if (str[i] == '-')
			if (i == 0)
				str.insert(0, 1, '0');
			else if (str[i - 1] == '(')
				str.insert(i, 1, '0');
	return str;
}

void Calculator::infix_to_suffix()//中缀转化为后缀 
{
	stack<char> symbol;
	const char c='#';
	infix.insert(0,1,c);
	infix.insert(infix.size(),"#");//将表达式两端插入#分隔，保证结束的条件 
	int j=0;
	for(int i=0;i<infix.size();i++){
		if(isNumber(infix[i])){//数字直接压入，同时加入&分隔 
			postfix.push_back(infix[i]);
			postfix.push_back('&');
		}
		else{
			if(symbol.isempty() || outStack(infix[i])>inStack(symbol.returntop())){//判断栈内栈外元素的优先级，大于则压入 
				symbol.add(infix[i]);
			}
			else{
				while(outStack(infix[i])<inStack(symbol.returntop())){//栈内优先级高，符号栈中弹出符号压入后缀表达式 
					postfix.push_back(symbol.del());
				}
				if(outStack(infix[i])==inStack(symbol.returntop())){//优先级相等，（），##，符号栈中弹出 
					symbol.del();
				}
				else{
					symbol.add(infix[i]);//栈内优先级较低，直接压入 
				}
			}
		}
	}
}

double Calculator::returnnum(char *c, int n) //返回字符对应的数,n表示个十百千位
{
    int l = n;
    double num = 0;
    double m = 1;
    for (int i = l - 1; i >= 0; i--) {
        num += toNum(c[i]) * m;
        m *= 10;
    }
    return num;
}
void Calculator::cal_suffix()
{
	char *temp=new char [100];
    infix_to_suffix(); //将中缀表达式转换为后缀表达式
    for(int i=0,j=0;i<postfix.size();i++){
    	if(isNumber(postfix[i])){
    		int f=0;
    		if(postfix[i]=='0' && isNumber(postfix[i+1])){
    			f=1;
    			i++;
			}
    		while(isNumber(postfix[i])){
    			*(temp+j)=postfix[i];
    			i++;j++;
			}
			if(f){
				poststack.add(-returnnum(temp,j));
			}
			poststack.add(returnnum(temp,j));
			j=0;
		}
		if(!isNumber(postfix[i])){
			if(postfix[i]=='&'){
				continue;
			}
			cal(postfix[i]);
			if(flag){
				cout << "重新输入 并检查表达式的合法性" << endl;
				exit(0);
			}
		}
	}
	
}

bool Calculator::Get_operands(double& left, double& right)
{
    if (poststack.isempty()) {
        cout << "缺少左操作数" << endl;
        flag=1;
        return false;
    }
    right = poststack.del();
    if (poststack.isempty()) {
        cout << "缺少右操作数" << endl;
        flag=1;
        return false;
    }
    left = poststack.del();
    return true; //返回true
}

int Calculator::inStack(char c)
{
    switch (c) {
    case '#':
        return 0;
        break;
    case '(':
        return 1;
        break;
    case '*':
    case '/':
    case '%':
        return 5;
        break;
    case '+':
    case '-':
        return 3;
        break;
    case ')':
        return 6;
        break;
    }
}
//返回操作符的栈外优先级
int Calculator::outStack(char c)
{
    switch (c) {
    case '#':
        return 0;
        break;
    case '(':
        return 6;
        break;
    case '*':
    case '/':
    case '%':
        return 4;
        break;
    case '+':
    case '-':
        return 2;
        break;
    case ')':
        return 1;
        break;
    }
}
//判断是否为操作数
bool Calculator::isNumber(char ch)
{
    if (48 <= ch && ch <= 57)
        return true;
    else
        return false;
}

//数值型字符转换为数字
float Calculator::toNum(char num_ch)
{
    switch (num_ch) {
    case '0':
        return 0;
        break;
    case '1':
        return 1;
        break;
    case '2':
        return 2;
        break;
    case '3':
        return 3;
        break;
    case '4':
        return 4;
        break;
    case '5':
        return 5;
        break;
    case '6':
        return 6;
        break;
    case '7':
        return 7;
        break;
    case '8':
        return 8;
        break;
    case '9':
        return 9;
        break;
    }
}
//根据操作符 去栈中去取两个元素计算
void Calculator::cal(char cp)
{
    double left, right, value;
    if (Get_operands(left, right)) {
        switch (cp) {
        case '+': {
            value = left + right;
            poststack.add(value); //相加后结果压栈
            break;
        }
        case '-': {
            value = left - right;
            poststack.add(value); //相减 压栈
            break;
        }
        case '*': {
            value = left * right;
            poststack.add(value); //相乘 压栈
            break;
        }
        case '/':
            if (right == 0) {
                cout << "/ 操作符 右操作数为0" << endl;
                exit(1);
            } else {
                value = left / right;
                poststack.add(value); //相除 压栈
            }
            break;
        }
    }
}
//保留并输出最后结果
void Calculator::print()
{
    cout << "表达式计算结果:" << endl;
    cout << poststack.returntop() << endl;
}
int main()
{
    string str;
    cout << "输入一个中缀表达式：" << endl;
    cin >> str;
    str = format(str);
    Calculator calculator(str);
    calculator.cal_suffix();
    calculator.print(); //显示结果
    return 0;
}


