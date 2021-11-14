#include <iostream>
using namespace std;

template <class T>
class LinkNode {
public:
    T data; //������
    LinkNode<T>* link; //ָ����ָ��Ľ��
    LinkNode(const T& el, LinkNode<T>* ptr = 0)
    {
        data = el;
        link = ptr;
    }
};
template <class T>
class LinkStack {
public:
    LinkStack()
    {
        top = NULL;
        size = 0;
    }
    ~LinkStack()
    {
        Clear();
    }
    void Clear()
    {
        while (top != NULL) {
            LinkNode<T>* tmp = top;
            top = top->link;
            delete tmp;
        }
        size = 0;
    }

    /*
	TODO:1.4-a.	��ջ����,��item��ջ��������true
	 */
    bool Push(const T item)
    {
    	LinkNode<T> *temp=new LinkNode<T>(item,top);
		top=temp;
		size++;
		return true;
    }
    /*
	TODO:1.4-b.	��ջ���������ж�ջ�Ƿ�Ϊ�գ���ջ��Ԫ�ظ�ֵ��item
	����ֵ˵������ջ�ɹ�������true�����򷵻�false
	ע�⣺���ջΪ�գ����ӡcout << "ջΪ�գ�����ִ�г�ջ����" << endl;������false
	 */
    bool Pop(T& item)
    {
    	if(size==0){
    		cout << "ջΪ�գ�����ִ�г�ջ����" << endl;
    		return false;
		}
		item=top->data;
		top=top->link;
		size--;
		return true;
    }
    /*
	TODO��1.4-c.	��ȡջ��Ԫ�أ�����ɾ�����ж�ջ�Ƿ�Ϊ�ա�
	���ջΪ�գ��������ӡcout << "ջΪ�գ����ܶ�ȡջ��Ԫ��" << endl;������false��
	���򣬽�ջ��Ԫ�ػ�ȡ����ֵ��item, ����true��
	 */
    bool Top(T& item)
    {
    	if(size==0){
    		cout << "ջΪ�գ����ܶ�ȡջ��Ԫ��" << endl;
    		return false;
		}
		item=top->data;
    }

private:
    LinkNode<T>* top; //ָ����ʽջջ����ָ��
    int size; //ջ��Ԫ�ظ���
};

int main()
{
    LinkStack<int> ls;
    int iNum, temp, temp1 = -1, temp2 = -1;
    cin >> iNum;
    for (int i = 0; i < iNum; i++) {
        ls.Push(i * 10);
    }
    cout << "����һ����ջ����";n
    cin >> temp;
    if (temp != 99999) {
        ls.Push(temp);
    }
    ls.Pop(temp1);
    cout << "��ջ��" << temp1 << endl;
    ls.Top(temp2);
    cout << "��ȡջ��Ԫ�أ�" << temp2 << endl;
    return 0;
}

