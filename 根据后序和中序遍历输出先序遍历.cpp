#include<iostream>
using namespace std;
struct Node{
	int data;
	Node *right;
	Node *left;
};
Node *create(int *post,int *in,int n){
	if(n==0)
		return NULL;
	int *mid=in;
	while(*mid!=*(post+n-1))
		mid++;
	Node *temp=new Node;
	temp->data=*mid;
	int m=mid-in;
	temp->left=create(post,in,m);
	temp->right=create(post+m,mid+1,n-m-1);
	return temp; 
}
void caculate(Node *head){
	if(head){
		cout<<" "<<head->data;
		caculate(head->left);
		caculate(head->right);
	}
}
int main(){
	int n;
	cin>>n;
	int post[30],in[30];
	for(int i=0;i<n;i++){
		cin>>post[i];
	}
	for(int i=0;i<n;i++){
		cin>>in[i];
	}
	cout<<"Preorder:";
	caculate(create(post,in,n));
}
