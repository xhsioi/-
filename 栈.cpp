#include<iostream>
#include<string>
using namespace std;
int flag=0;

template<class T>
class Stack{
	private:
		int max;
		int top;
		T *data;
	public:
		Stack(int maxsize=10){
			top=-1;
			max=maxsize-1;
			data=new T[maxsize];
		}
		bool isEmpty(){
			return top==-1;
		}
		bool isFull(){
			return top==max;
		}
		bool push(const T &x){
			if(isFull()){
				cout<<"no memory"<<endl;
				return false;
			}
			data[++top]=x;
			return true;
		}
		T pop(){
			if(isEmpty()){
				cout<<"no element"<<endl;
			}
			T temp=data[top];
			top--;
			return temp;
		}
		T toTop(){
			return data[top];
		}
		void print(){
			if(isEmpty()){
				cout<<"no element"<<endl;
				return;
			}
			else{
				for(int i=0;i<=top;i++){
					cout<<data[i]<<'\t';
				}
				cout<<endl;
			}
		} 
};
