#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
double answer[3];
int a,b,c,d;
int num=0;
void caculate(double left,double right){
	double middle=(left+right)/2;
	double ans1=a*pow(left,3)+b*pow(left,2)+c*left+d;
	double ans2=a*pow(right,3)+b*pow(right,2)+c*right+d;
	double ans3=a*pow(middle,3)+b*pow(middle,2)+c*middle+d;
	if(ans1==0){
		answer[num++]=left;
		left++;
	}
	if(ans3==0){
		answer[num++]=middle;
		if(num==3)
			return;
		caculate(left,middle-1);
		caculate(middle+1,right);
	}
	if(ans2==0){
		answer[num++]=right;
		right--;
	}
	if(num==3)
		return;
	if(ans1*ans3<0){
		caculate(left,middle);
	}
	if(ans2*ans3<0){
		caculate(middle,right);
	}
} 
int main(){
	cin>>a>>b>>c>>d;
	caculate(-100.0,100.0);
	sort(answer,&answer[2]);
	printf("%.2f %.2f %.2f",answer[0],answer[1],answer[2]);
	return 0;
}
