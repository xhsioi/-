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
		bool push(T x){
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
		int reutrnSize(){
			return (rear-front)%max;
		}
		void Clear(){
			delete [] data;
		}
		void show(){
			for(int i=0;i<(rear-front)%max;i++){
				if(data[(front+1+i)%max]==0){
					continue;
				}
				cout<<data[(front+1+i)%max]<<" ";
			}
			cout<<endl;
		}
}; 
int main(){
	int n;
	int flag=0;
	LinkedQueue<int> list(1000);
	list.push(0);
	list.push(1);
	list.push(0);
	int size=list.reutrnSize();
	cin>>n;
	cout<<"1"<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<size;j++){
			if(list.top()==0 && flag){
				list.push(0);
				flag=0;
				size=list.reutrnSize();
				break;
			}
			if(list.top()==0 && j==0){
				flag=1;
			}
			int temp=list.top();
			list.pop();
			temp+=list.top();
			list.push(temp);
		}
		list.show();
	}
	return 0;
} 
