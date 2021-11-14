#include<iostream>
#include<string>
using namespace std;
void getNext(string q,int *next){
	int len=q.length();
	next[0]=0;
	for(int i=1,j=0;i<len;i++){
		if(q[i]==q[j]){
			next[i]=next[i-1]+1;
			j++;
		}
		else{
			j=0;
			next[i]=0;
		}
	}
} 
int KMP(string p,string q,int *next){
	int i=0,j=0;
	int len=p.length();
	while(i<len){
		if(p[i]==q[j]){
			i++;j++;
			if(j==q.length()){
				return i-j;
			}
		}
		else{
			if(j!=0){
				j=next[j-1];
			}
			else{
				i++;
			}
		}
	}
	return -1;
}
int main(){
	string p,q;
	cin>>p;
	cin>>q;
	int *next=new int [100];
	getNext(q,next);
	cout<<KMP(p,q,next);
	return 0;
}

