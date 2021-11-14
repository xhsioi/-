/*1.1 ˳���

	bool Insert(const int p, const T value);        //1.1-b ��λ��p����Ԫ��value,��ĳ�������1
	bool Delete(const int p);                       //1.1-d ɾ��λ��p����Ԫ�أ���ĳ��ȼ�1
	int GetPos(const T x);					    	//1.1-c ����ֵΪx��Ԫ�ص�λ��

*/
#include <iostream>
using namespace std;

#pragma once
template <class T>
class List {
public:
    void Clear(); //�ÿ����Ա�
    bool IsEmpty(); //���Ա�Ϊ��ʱ������true
    bool Append(const T value); //�ڱ�β���Ԫ��value����ĳ�������1
    bool Insert(const int p, const T value); //��λ��p����Ԫ��value,��ĳ�������1
    bool Delete(const int p); //ɾ��λ��p����Ԫ�أ���ĳ��ȼ�1
    int GetPos(const T x); //��ֵΪx��Ԫ�ص�λ�÷��ص�����p��
};

template <class T> //���Ա��Ԫ������ΪT
class ArrayList : public List<T> //����˳���ArrayList
{
public: //˳�������㼯
    ArrayList(const int size) //����˳�����Ϊ��󳤶�
    {
        maxSize = size;
        arrayList = new T[maxSize];
        curLen = 0;
        position = 0;
    }
    ~ArrayList() //��������������ArrayList��ʵ��
    {
        delete[] arrayList;
    }
    void clear() //���˳���
    {
        delete[] arrayList;
        curLen = 0;
        position = 0;
        arrayList = new T[maxSize];
    }

    int Length(); //˳���ĳ���
    bool Append(const T value); //�ڱ�β���Ԫ��value����ĳ�������1

    bool Insert(const int p, const T value); //1.1-b ��λ��p����Ԫ��value,��ĳ�������1
    bool Delete(const int p); //1.1-d ɾ��λ��p����Ԫ�أ���ĳ��ȼ�1
    int GetPos(const T x); //1.1-c ����ֵΪx��Ԫ�ص�λ��
    void PrintArray(); //���˳�������
private:
    T* arrayList; //�洢˳����ʵ��
    int maxSize; //˳���ʵ������󳤶�
    int curLen; //˳���ʵ���ĵ�ǰ����
    int position; //��ǰ����λ��
};

template <class T>
int ArrayList<T>::Length()
{
    return curLen;
}

//�ڱ�β���Ԫ��value����ĳ�������1
template <class T>
bool ArrayList<T>::Append(const T value)
{
    if (curLen >= maxSize) //���˳����Ƿ����
    {
        cout << "The List is overflow" << endl;
        return false;
    }

    arrayList[curLen] = value; //��β��������Ԫ��
    curLen++; //���ʵ�ʳ�������1
    return true;
}

/*
TODO:1.1-b ��λ��p����Ԫ��value,��ĳ�������1��pΪҪ�����λ���±�ֵ�����磺p=0����ʾ��˳���ı�ͷ����Ԫ�ء�
����ֵ˵��������ɹ�������true�����򷵻�false
ע�����1�����˳����Ƿ�����������,���ӡcout << "The List is overflow" << endl;����false
          2��������λ���Ƿ�Ϸ��������Ϸ�����cout << "Insertion point is illegal" << endl; ����false
*/
template <class T>
bool ArrayList<T>::Insert(const int p, const T value)
{
    if(p<0 || p>curLen+1){
		cout << "Insertion point is illegal" << endl;
		return false;
	} 
	if(curLen>=maxSize){
		cout << "The List is overflow" << endl;
		return false;
	}
	if(p==curLen+1){
		curLen++;
		arrayList[p]=value;
		return true;
	}
	for(int i=curLen;i>=p;i--){
		arrayList[i+1]=arrayList[i];
	}
    curLen++;
    arrayList[p]=value;
    return true;
}
/*
TODO:1.1-d ɾ��λ��p����Ԫ�أ���ĳ��ȼ�1��pΪԪ�����ڵ��±�ֵ
����ֵ˵����ɾ���ɹ�������true�����򷵻�false
ע�����1�����˳�����û��Ԫ���ˣ����ӡcout << "No element to delete" << endl;������false
          2�����ɾ����λ��p�Ƿ�����pλ�ô���Ԫ�أ����ӡcout << "Deletion is illegal" << endl;������false
*/
template <class T>
bool ArrayList<T>::Delete(const int p)
{
    if(p<0 || p>curLen){
        cout << "Deletion is illegal" << endl;
        return false;
    }
    if(curLen==0){
        cout << "No element to delete" << endl;
        return false;
    }
    if(p==0 && curLen==1){
        clear();
        return true;
    }
    for(int i=p;i<curLen;i++){
        arrayList[i]=arrayList[i+1];
    }
    curLen--;
    return true;
}

/*
TODO:1.1-c ����ֵ˳����е�һ��ֵΪx�Ľ��λ���±�
����ֵ˵���������˳����д�ͷ��β�ҵ�xԪ�أ������̷���xԪ�����ڵ�λ���±ꡣ��������x��˳����е�һ��λ�ã��򷵻�0���Դ�����
            ����Ҳ���xԪ�أ��򷵻�-1
*/
template <class T>
int ArrayList<T>::GetPos(const T x)
{
    for(int i=0;i<=curLen;i++){
        if(x==arrayList[i]){
            return i;
        }
    }
    return -1;
}

//���˳�������
template <class T>
void ArrayList<T>::PrintArray()
{
    for (int i = 0; i < curLen; i++) {
        cout << arrayList[i] << " ";
    }
    cout << endl;
}
int main()
{
    int maxsize, pos0, pos1, value0, value1;
    cin >> maxsize >> pos0 >> pos1 >> value0 >> value1;
    ArrayList<int> arr(maxsize);
    int p;
    for (int i = 0; i < 5; i++) {
        arr.Append(i);
    }
    arr.PrintArray();
    arr.Insert(pos0, value0); //λ��pos0������value0
    arr.PrintArray();
    arr.Delete(pos1); //ɾ��λ��pos1����Ԫ��
    arr.PrintArray();
    p = arr.GetPos(value1); //���ֵΪvalue1�Ľ��λ��
    cout << p << endl;
    return 0;
}

