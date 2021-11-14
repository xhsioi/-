#include<iostream>
#include<cstdlib>
#define max 1001
using namespace std;
struct Tree{
	int data[max];
	int size;
};
int main(){
	int n,m1,m2,temp;
	cin>>n;
	Tree *t=new Tree;
	for(int i=1;i<=n;i++){
		cin>>t->data[i];
		t->size++;
	}
	t->data[0]=0;
	cin>>m1>>m2;
	if(!t->data[m1]){
		cout<<"ERROR: T["<<m1<<"] is NULL";
	}
	else if(!t->data[m2]){
		cout<<"ERROR: T["<<m2<<"] is NULL";
	}
	else{
		while(m1!=m2){
			if(m1>m2){
		    	temp=m1;
				m1=m2;
				m2=temp;
			}
			m2/=2;
		}
		cout<<m1<<" "<<t->data[m1];	
	}
}
