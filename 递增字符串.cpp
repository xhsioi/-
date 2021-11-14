#include<iostream>
#include<vector> 
using namespace std;
int main(){
	long n;
	int temp,left,right,templeft,tempright;
	int templength=1,length=1;
	vector<int> List;
	scanf("%ld",&n);
	while(n--){
		scanf("%d",&temp);
		List.push_back(temp);
	}
	left=right=0;
	for(int i=0;i<List.size();i++){
		if(List.size()==1)
			break;
		if(length==List.size())
			break;
		if(List[i+1]>List[i]){
			tempright=i+1;
			templength=tempright-templeft+1;
		}
		if(templength>length){
			length=templength;
			right=tempright;
			left=templeft;
			templength=1;
		}
		if(List[i+1]<=List[i]){
			tempright=templeft=i+1;
			templength=1;
		}
	}
	if(length==1){
		printf("%d",List[left]);
		return 0;
	}
	printf("%d",List[left]);
	for(int i=left+1;i<=right;i++){
		printf(" %d",List[i]);
	}
} 
