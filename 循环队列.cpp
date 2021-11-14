#include<iostream>
#include<vector>
using namespace std;
template <class T>
class LinkedQueue{
	private:
		int front;
		int rear;
		int max;
		T *data;
	public:
		LinkedQueue<T>(int maxsize=10){
			max=maxsize+1;
			front=rear=0;
			data =new T [max];
		}
		bool IsEmpty(){
			if(front%max==rear%max && front%max==0){
				return true;
			}
			return false;
		}
		bool IsFull(){
			return (rear+1)%max==front%max;
		}
		bool push(T &x){
			if(IsFull()){
				cout<<"Full"<<endl;
				return false;
			}
			rear++;
			data[rear]=x;
			return true;
		}
		bool pop(){
			if(IsEmpty()){
				return false;
			}
			front++;
			return true;
		}
		T top(){
			return data[(front+1)%max];
		}
		void Clear(){
			delete [] data;
		}
		void show(){
			for(int i=0;i<(rear-front)%max;i++){
				cout<<data[(front+1+i)%max]<<" ";
			}
			cout<<endl;
		}
}; 
int main(){
	int size;
	int num[100];
	cin>>size;
	for(int i=0;i<size;i++){
		cin>>num[i];
	}
	LinkedQueue<int> list(size);
	if(list.IsEmpty()){
		cout<<"empty"<<endl;
	}
	else{
		cout<<"not empty"<<endl;
	}
	for(int i=0;i<size;i++){
		list.push(num[i]);
	}
	list.push(size);
	list.show();
	cout<<list.top()<<endl;
	list.pop();
	list.show();
	return 0;
}
