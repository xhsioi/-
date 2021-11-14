#include <cstdlib>
#include <iostream>
#include <string>
int flag=0;
using namespace std;
//-5*(-2+9*6)-2+3*5=-247

template <class T>
class stack {
private:
    int top; //ջ��
    int maxtop; //����ջ��ֵ
    T* st; //��ջԪ������
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
    string infix; //��׺���ʽ
    string postfix; //��׺���ʽ
    stack<double> poststack; //��׺ջ
    Calculator(string str);
    ~Calculator()
    {
        poststack.clear();
    }
    void infix_to_suffix(); //1.4-e  ����׺���ʽת��Ϊ��׺���
    int inStack(char ch); //ջ�����ȼ�
    int outStack(char ch); //ջ�����ȼ���
    void cal_suffix(); //������׺���ʽ��ֵ
    void print();
    bool Get_operands(double& left, double& right);
    bool isNumber(char ch);
    double returnnum(char *c,int n); //�����ַ���Ӧ����
    float toNum(char num_ch); //��ֵ���ַ�ת��������
    void cal(char ch); //���ݲ����� ȥջ��ȥȡ����Ԫ�ؼ���
};
Calculator::Calculator(string str)
{
    infix = str;
}

string format(string str) {//�����ʽ�еĸ���ת����0-��������ʽ					
	for (int i = 0; i < str.length(); i++)	
		if (str[i] == '-')
			if (i == 0)
				str.insert(0, 1, '0');
			else if (str[i - 1] == '(')
				str.insert(i, 1, '0');
	return str;
}

void Calculator::infix_to_suffix()//��׺ת��Ϊ��׺ 
{
	stack<char> symbol;
	const char c='#';
	infix.insert(0,1,c);
	infix.insert(infix.size(),"#");//�����ʽ���˲���#�ָ�����֤���������� 
	int j=0;
	for(int i=0;i<infix.size();i++){
		if(isNumber(infix[i])){//����ֱ��ѹ�룬ͬʱ����&�ָ� 
			postfix.push_back(infix[i]);
			postfix.push_back('&');
		}
		else{
			if(symbol.isempty() || outStack(infix[i])>inStack(symbol.returntop())){//�ж�ջ��ջ��Ԫ�ص����ȼ���������ѹ�� 
				symbol.add(infix[i]);
			}
			else{
				while(outStack(infix[i])<inStack(symbol.returntop())){//ջ�����ȼ��ߣ�����ջ�е�������ѹ���׺���ʽ 
					postfix.push_back(symbol.del());
				}
				if(outStack(infix[i])==inStack(symbol.returntop())){//���ȼ���ȣ�������##������ջ�е��� 
					symbol.del();
				}
				else{
					symbol.add(infix[i]);//ջ�����ȼ��ϵͣ�ֱ��ѹ�� 
				}
			}
		}
	}
}

double Calculator::returnnum(char *c, int n) //�����ַ���Ӧ����,n��ʾ��ʮ��ǧλ
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
    infix_to_suffix(); //����׺���ʽת��Ϊ��׺���ʽ
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
				cout << "�������� �������ʽ�ĺϷ���" << endl;
				exit(0);
			}
		}
	}
	
}

bool Calculator::Get_operands(double& left, double& right)
{
    if (poststack.isempty()) {
        cout << "ȱ���������" << endl;
        flag=1;
        return false;
    }
    right = poststack.del();
    if (poststack.isempty()) {
        cout << "ȱ���Ҳ�����" << endl;
        flag=1;
        return false;
    }
    left = poststack.del();
    return true; //����true
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
//���ز�������ջ�����ȼ�
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
//�ж��Ƿ�Ϊ������
bool Calculator::isNumber(char ch)
{
    if (48 <= ch && ch <= 57)
        return true;
    else
        return false;
}

//��ֵ���ַ�ת��Ϊ����
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
//���ݲ����� ȥջ��ȥȡ����Ԫ�ؼ���
void Calculator::cal(char cp)
{
    double left, right, value;
    if (Get_operands(left, right)) {
        switch (cp) {
        case '+': {
            value = left + right;
            poststack.add(value); //��Ӻ���ѹջ
            break;
        }
        case '-': {
            value = left - right;
            poststack.add(value); //��� ѹջ
            break;
        }
        case '*': {
            value = left * right;
            poststack.add(value); //��� ѹջ
            break;
        }
        case '/':
            if (right == 0) {
                cout << "/ ������ �Ҳ�����Ϊ0" << endl;
                exit(1);
            } else {
                value = left / right;
                poststack.add(value); //��� ѹջ
            }
            break;
        }
    }
}
//��������������
void Calculator::print()
{
    cout << "���ʽ������:" << endl;
    cout << poststack.returntop() << endl;
}
int main()
{
    string str;
    cout << "����һ����׺���ʽ��" << endl;
    cin >> str;
    str = format(str);
    Calculator calculator(str);
    calculator.cal_suffix();
    calculator.print(); //��ʾ���
    return 0;
}


