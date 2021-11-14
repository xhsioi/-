#include<iostream>
using namespace std;
char a[7]={};//先序遍历数组 
char b[7]={};//中序遍历数组 
char c[7]={};//后序遍历数组 
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
		BinaryTree(Node *rt=NULL){
			root=rt;
		}
		Node *getRoot(){
			return root;
		}
		void createTree1(){
			Node *pc=new Node('c',0,0);
			Node *pd=new Node('d',0,0);
			Node *pb=new Node('b',pc,pd);
			root=new Node('a',pb,0);
		}
		void createTree2(){
			Node *pd=new Node('d',0,0);
			Node *pe=new Node('e',0,0);
			Node *pf=new Node('f',0,0);
			Node *pg=new Node('g',0,0);
			Node *pb=new Node('b',pd,pe);
			Node *pc=new Node('c',pf,pg);
			root=new Node('a',pb,pc);
		}
		void levelOrder(){//广度优先遍历 
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
			cout<<"层数："<<answer<<endl;
		}
		void preOrder1(Node *head){//先序遍历递归形式 
			if(head){
				cout<<head->data<<endl;
				preOrder1(head->left);
				preOrder1(head->right);	
			} 
		} 
		void preOrder2(){//先序遍历非递归形式 
			Node *temp=root;
			Stack<Node*> s;
			int i=0; 
			while(temp || !s.isEmpty()){
				if(temp){
					cout<<temp->data<<endl;
					a[i++]=temp->data;
					s.push(temp);
					temp=temp->left;
				}
				else{
					if(!s.isEmpty()){
						temp=s.pop();
						temp=temp->right;
					}
				}
			}
		}
		void midOrder1(Node *head){//中序遍历递归形式 
			if(head){
				midOrder1(head->left);
				cout<<head->data<<endl;
				midOrder1(head->right);	
			} 
		}
		void midOrder2(){//中序遍历非递归形式 
			Node *temp=root;
			Stack<Node*> s;
			int i=0;
			while(temp || !s.isEmpty()){
				if(temp){
					s.push(temp);
					temp=temp->left;
				}
				else{
					if(!s.isEmpty()){
						temp=s.pop();
						b[i++]=temp->data;
						cout<<temp->data<<endl;
						temp=temp->right;
					}
				}
			}
		}
		void lasOrder1(Node *head){//后序遍历递归形式 
			if(head){
				lasOrder1(head->left);
				lasOrder1(head->right);
				cout<<head->data<<endl;	
			} 
		}
		void lasOrder2(){//后序遍历非递归形式 
			Node *head=root;
			Node *pre=root;
			Stack<Node*> s;
			int i=0;
			while(head){
				while(head->left){
					s.push(head);
					head=head->left;
				}//将指针指向最左边的节点 
				while(head && (head->right==NULL || head->right==pre)){
					cout<<head->data<<endl;//输出当前子树的最左边元素
					c[i++]=head->data; 
					pre=head;//记录前一个访问的节点 
					if(s.isEmpty()){
						return;
					}
					head=s.toTop();
					s.pop();
				}
				s.push(head);
				head=head->right;
			}
		}
};
Node* preAndmid(int s1,int e1,int s2,int e2){//先序数组的起点、终点、中序数组的起点、终点 
	Node *root=new Node(a[s1]);		
	int num;
	for(int i=s2;i<=e2;i++){
		if(b[i]==a[s1]){
			num=i;//找到根节点在中序数组中的位置； 
			break;
		}
	}
	if(num!=s2){//如果还存在左子树 
		root->left=preAndmid(s1+1,s1+(num-s2),s2,num-1);
	}
	if(num!=e2){//如果还存在右子树 
		root->right=preAndmid(s1+(num-s2)+1,e1,num+1,e2);
	}
	return root;
}
int main(){
//	BinaryTree t1;
//	t1.createTree1();
//	cout<<"广度优先遍历："<<endl; 
//	t1.levelOrder();
	BinaryTree t2;
	t2.createTree2();
	t2.levelOrder();
	cout<<"先序遍历递归"<<endl;
	t2.preOrder1(t2.getRoot());
	cout<<"先序遍历非递归"<<endl;
	t2.preOrder2();
	cout<<"中序遍历递归"<<endl;
	t2.midOrder1(t2.getRoot());
	cout<<"中序遍历非递归"<<endl;
	t2.midOrder2();
	cout<<"后序遍历递归"<<endl;
	t2.lasOrder1(t2.getRoot());
	cout<<"后序遍历非递归"<<endl;
	t2.lasOrder2();
	cout<<"先序、中序、后序数组储存："<<endl;
	for(int i=0;i<7;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	for(int i=0;i<7;i++){
		cout<<b[i]<<" ";
	}
	cout<<endl;
	for(int i=0;i<7;i++){
		cout<<c[i]<<" ";
	}
	cout<<endl; 
	Node *root=preAndmid(0,6,0,6);
	BinaryTree t3(root);
	cout<<"前序和中序确定树"<<endl;
	cout<<"树的后序遍历"<<endl; 
	t3.lasOrder2(); 
} 

