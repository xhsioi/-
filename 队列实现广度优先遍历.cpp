#include<iostream>
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
			if(front%max==rear%max){
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
class Node{
	public:
		char data;
		Node *left;
		Node *right;
		Node(int dt,Node *l=0,Node *r=0){
			data=dt;
			left=l;
			right=r;
		}
}; 
class BinaryTree{
	private:
		Node *root;
	public:
		BinaryTree(){
			root=0;
		}
		void createTree(){
			Node *pc=new Node('c',0,0);
			Node *pd=new Node('d',0,0);
			Node *pb=new Node('b',pc,pd);
			root=new Node('a',pb,0);
		}
		void levelOrder(){
			LinkedQueue<Node*> queue(10);
			queue.push(root);
			int number=0,answer=1;
			while(!queue.IsEmpty()){
				Node *temp=queue.top();
				if(temp->left){
					queue.push(temp->left);
					number++;
				}
				if(temp->right){
					queue.push(temp->right);
					number++;
				}
				if(number){
					answer++;
					number=0;
				}
				cout<<temp->data<<" ";
				queue.pop();
			}
			cout<<endl;
			cout<<"²ãÊý£º"<<answer<<endl;
		}
};
int main(){
	BinaryTree t;
	t.createTree();
	t.levelOrder();
} 
