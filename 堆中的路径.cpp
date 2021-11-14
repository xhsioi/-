#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
struct Node{
	int data;
	Node *right;
	Node *left;
};
Node *serchleft(Node *head,int flag){
	int num=0;
	for(int i=0;i<flag;i++){
		if(i%2==0)
		num++;
	}
	for(int i=0;i<=num;i++){
		head=head->left;
	}
	return head;
}
Node *create(vector<int> num){
	int flag=-1;
	Node *Head=new Node;
	Node *head=new Node;
	Node *temp=new Node;
	for(int i=0;i<num.size();i++){
		Node *temp=new Node;
		temp->data=num[i]
		if(i==0){
			head=Head=temp;
			continue;
		}
		if(Head->left==NULL){
			Head->left=temp;
			continue;
		}
		if(Head->right==NULL){
			Head->right=temp;
			flag++;
		}
		if(flag==)
		if(Head->left && Head->right){
			if(flag%2==0 && flag){
				Head=searchleft(head,flag);
			}
			else{
				Head=
			}
		}
	}
}
int main(){
	vector<int> num,pos;
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin<<num[i];
	}
	for(int i=0;i<m;i++){
		cin<<pos[i];
	}
	Node *head=create(num);
}
