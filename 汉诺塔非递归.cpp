#include<iostream>
#include<stack>
using namespace std;
struct Node{
	int n;
	char a,b,c;
	Node(char a,char b,char c,int n):a(a),b(b),c(c),n(n){
	}
};
int main(){
	int n;
	cin>>n;
	stack<Node> s;
	s.push(Node('a','b','c',n));
	while(!s.empty()){
		Node t=s.top();
		s.pop();
		if(t.n==1)
			printf("%c -> %c\n",t.a,t.c);
		else{
			s.push(Node(t.b,t.a,t.c,t.n-1));
			s.push(Node(t.a,t.b,t.c,1));
			s.push(Node(t.a,t.c,t.b,t.n-1));
		}
	}
	return 0;
}
