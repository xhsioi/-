#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
using namespace std;
int n,m,flagn,flagm;
int a[8][2]={-1,-2,-2,-1,-2,1,-1,2,1,2,2,1,2,-1,1,-2};
int b[4][2]={1,0,-1,0,0,1,0,-1};
int wayNum=0;
int chess[21][21]={0};
int findway(int tempn,int tempm,int stop){
	for(int i=0;i<4;i++){
		if(tempn+b[i][0]==n && tempm+b[i][1]==m)
			return 1;
		if(!chess[tempn+b[i][0]][tempm+b[i][1]] && tempn+b[i][0]>=0 && tempn+b[i][0]<=n && tempm+b[i][1]>=0 && tempm+b[i][1]<=m){
			cout<<"1"<<endl;
			wayNum+=findway(tempn+b[i][0],tempm+b[i][1]);
		}
	}
	return 0;
}
int main(){
	int num;
	cin>>n>>m>>flagn>>flagm;
	if(m>20 || flagn>20 || flagm>20 || n>20){
		return 0;
	}
	for(int i=0;i<8;i++){
		if(a[i][0]+flagn<0 || a[i][0]+flagn>n || a[i][1]+flagm>m || a[i][1]+flagm<0){
			continue;
		}
		chess[a[i][0]+flagn][a[i][1]+flagm]=1;
	}
	num=findway(0,0,4);
	cout<<num<<endl;
	return 0;
} 
