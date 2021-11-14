#include<iostream>
using namespace std;
template<class T>
class Stack{
	private:
		int max;
		T *head;
		int top;
	public:
		Stack(int max){
			top=-1;
			this.max=max;
			head=new T[max];
		}
		bool Isempty(){
			return top==-1;
		}
		void push(T temp){
			top++;
			*(head+top)=temp;
		}
		void pop(){
			top--;
		}
		T top(){
			return head[top];
		}
		bool Isfull(){
			return (top+1)==max;
		}
		void Clear(){
			while(top>-1){
				delete head[top--];
			}
		}
};
