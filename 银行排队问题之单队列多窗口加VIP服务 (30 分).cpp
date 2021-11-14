#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Costumer{
	public:
		int time;
		int length;
		int VIP;
		int wait;
		Costumer(){
			wait=time=length=0;
			VIP=false;
		}
}; 
int main(){
	Costumer cos[1005];
	Costumer windows[15];
	int winNum[15]={0};
	int n,m,vipNum,t,flag,j,Sum=0,max=0,last=0,min;
	double Pre=0.0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>cos[i].time;
		cin>>cos[i].length;
		cin>>cos[i].VIP;
	}
	cin>>m;
	cin>>vipNum;
	t=cos[1].time;//初始化时间 
	for(int i=1;i<=n;i++){
		//重新设置t
		t=cos[i].time;
		//计算等待时间
		if(windows[vipNum].length==0 && cos[i].VIP){
			windows[vipNum]=cos[i];
			continue;
		} 
		min=windows[1].length+windows[1].time-t;
		for(j=1;j<=m;j++){
			if(j==vipNum && !cos[i].VIP){
				j++;
			}
			if(windows[j].length==0){
				flag=j;break;
			}
			if(min>(windows[j].length+windows[j].time-t)){
				min=windows[j].length+windows[j].time-t;
				flag=j;
			} 
		}
		if(!flag){
			for(int j=1;j<=m;j++){
				if(windows[j].length+windows[j].time-t==min)
					break;
			}	
		}
		cos[i].wait=min;
		winNum[j]++;
		cout<<j<<" "<<winNum[j]<<endl;
		
		//带入窗口
		cos[i].time=windows[j].time+windows[j].length;
		windows[j]=cos[i]; 
	}
	for(int i=1;i<=n;i++){
		Pre=Pre+cos[i].wait;
		if(cos[i].wait>max){
			max=cos[i].wait;
		}
	}
	for(int i=1;i<=m;i++){
		if(last<windows[i].length+windows[i].time){
			last=windows[i].length+windows[i].time;
		}
	}
	Pre=Pre/n;
	printf("%.1f %d %d\n",Pre,max,last);
	cout<<winNum[1];
	for(int i=2;i<=m;i++){
		cout<<" "<<winNum[i];
	}
	return 0;
}
