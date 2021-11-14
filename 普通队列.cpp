#include <iostream>
using namespace std;

template <class T>
class ArrayQueue {
private:
    int maxSize; //�����������
    int front;
    int rear;
    int* queue;

public:
    ArrayQueue(int size)
    {
        maxSize = size + 1;
        queue = new T[maxSize];
        front = rear = 0;
    }
    ~ArrayQueue()
    {
        delete[] queue;
    }

    void Clear()
    {
        front = rear;
    }

    /*
	TODO��1.5-a.��Ӳ������ж϶����Ƿ�Ϊ������������������������ӡcout << "�������������" << endl;������false��
	���򣬽�ֵitem������Ӳ�����������true
	����ֵ˵������ӳɹ�������true�����򷵻�false
	 */
    bool EnQueue(const T item)
    {
    	if(front==0){
            front=1;
            rear=1;
        }
    	if(front%maxSize+1==rear%maxSize){
    		cout << "�������������" << endl;
    		return false;
		}
		front++;
        queue[front%maxSize]=item;
        return true;
    }
    /*
	TODO��1.5-b.���ض�ͷԪ�أ���ɾ����Ԫ�أ��ж϶����Ƿ�Ϊ��
	�������Ϊ�գ��������ӡcout << "����Ϊ��" << endl;������false��
	���򽫶���ͷԪ��ȡ������ֵ��item������ɾ����Ԫ�أ�����true
	����ֵ˵�����ɹ���ȡ��ͷԪ�ط���true�����򷵻�false
	 */
    bool DeQueue(T& item)
    {
    	if(front==rear){
    		cout << "����Ϊ��" << endl;
    		return false;
		}
		item=queue[(rear+1)%maxSize];
		rear++;
		return true;
    }
    /*
	TODO��1.5-c.	���ض�ͷԪ�أ�����ɾ�����ж϶����Ƿ�Ϊ��
	�������Ϊ�գ����ӡcout << "����Ϊ��" << endl;������false��
	����ȡ����ͷԪ�ظ�ֵ��item������true��
	����ֵ˵�����ɹ���ȡ��ͷԪ�أ�����true�����򷵻�false
	 */
    bool GetFront(T& item)
    {
    	if(front==rear){
    		cout<<"����Ϊ��"<<endl;
    		return false;
		}
		item=queue[(rear+1)%maxSize];
		return true;
    }

    bool IsEmpty()
    {
        if (front == rear) {
            cout << "����Ϊ��" << endl;
            return true;
        } else {
            return false;
        }
    }
    bool IsFull()
    {
        if ((rear + 1) % maxSize == front) {
            cout << "�������������" << endl;
            return true;
        } else {
            return false;
        }
    }
};

int main()
{
    int maxsize = 0, iNum = 0, temp1 = 0, temp2 = 0, temp3 = 0;
    cin >> maxsize >> iNum >> temp1;
    ArrayQueue<int> aq(maxsize);
    for (int i = 0; i < iNum; i++) {
        aq.EnQueue(i * 3);
    }
    aq.EnQueue(temp1);
    aq.DeQueue(temp2);
    cout << "���ӣ�" << temp2 << endl;
    aq.GetFront(temp3);
    cout << "��ȡ��ͷԪ�أ�" << temp3 << endl;
    return 0;
}
