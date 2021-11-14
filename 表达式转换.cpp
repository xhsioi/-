#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
	string str;
	cin>>str;
	vector<char> nums,syms,points,ans;
	for(int i=0,k=0;i<str.length();i++){
		if(str[i]=='(')
			while(str[i++]!=')');
		if(str[i]=='+' || str[i]=='-'){
			points[i]=1;
		}
	}
	for(int i=0;i<points.size();i++){
		if(points[i]==1){
			ans.insert(ans.end(),nums.begin(),nums.end());
			ans.insert(ans.end(),syms.begin(),syms.end());
			nums.clear();
			syms.clear();
				cout<<ans[0]<<endl;
		}
		if(str[i]>=48 && str[i]<=57){
			nums.push_back(str[i]);
		}
		else if(str[i]!='(' && str[i]!=')'){
			syms.push_back(str[i]);
		}
	}
	cout<<ans[0]<<endl;
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<" ";
	}
}
