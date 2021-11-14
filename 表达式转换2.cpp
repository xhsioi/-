#include<iostream>
using namespace std;
#include<string>
int Compare(char c){
	switch(c){
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;
	}
}
int main(){
	string str;
	char a[21],b[21]={};
	cin>>str;
	for(int i=0,j=0,k=0;i<str.length();i++){
		if(str[i]>=48 && str[i]<=57){
			a[j++]=str[i];
		}
		else{
			if(b[0]=='\0')
				b[k]=str[i];
			if(Compare(str[i])>=Compare(b[k]))
				b[++k]=str[i];
			if(Compare(str[i])<Compare(b[k])){
				while(Compare(str[i])<Compare(b[k])){
					a[j++]=b[k];
				b[k]=str[i];
				}
			}
			if(str[i]=='('){
				b[++k]=str[i];
			}
			if(str[i]==')'){
				for(int l=k;b[l]!=')';l--){
					s[j++]=b[l];
				}
				b[l]='\0';
				k=l-1;
			}
		}
	}
}
