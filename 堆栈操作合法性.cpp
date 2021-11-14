#include<iostream>
#include<string>
#include<math.h>
using namespace std;
bool check(string str){
	
}
int main(){
	int n,m,Snum,Xnum,num;
	int flag=0;
	Snum=Xnum=0;
	scanf("%d %d",&n,&m);
	num=n;
	while(num--){
		string str;
		cin>>str;
		if(str.length()==0){
			flag=1;
			continue;
		}
		for(int i=0;i<str.length();i++){
			if(str[i]=='S')
				Snum++;
			if(str[i]=='X')
				Xnum++;
			if(Xnum+Snum==str.length() && Xnum==Snum)
				flag=1;
			if(Xnum-Snum>0 || Snum-Xnum>m)
				break;			
		}
		if(flag && num==0)
			printf("YES");
		if(!flag && num==0)
			printf("NO");
		if(flag && num!=0)
			printf("YES\n");
		if(!flag && num!=0)
			printf("NO\n");
		Xnum=Snum=flag=0;
	}
} 
