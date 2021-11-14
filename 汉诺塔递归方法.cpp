#include<iostream>
using namespace std;
void Hanota(int n,char a,char b,char c){
	if(n==1){
		printf("%c -> %c\n",a,c);
		return;
	}
	else{
		Hanota(n-1,a,c,b);
		Hanota(1,a,b,c);
		Hanota(n-1,b,a,c);
	}
}
int main(){
	int n;
	cin>>n;
	char a='a';
	char b='b';
	char c='c';
	Hanota(n,a,b,c);
	return 0;
}
