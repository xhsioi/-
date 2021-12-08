#include <iostream>
#include <vector>
#include <cstring>
#define INF 1000000
using namespace std;
const int N=6;
float g[6][6] = {{INF, 7, 4, 1, 2, INF},
             {7,INF,1,1,INF,4},
             {4,1,INF,INF,8,9},
             {1,1,INF,INF,INF,7},
             {2,INF,8,INF,INF,1},
             {INF,4,9,7,1,INF}
};
template<class T>
class Stack{
private:
    int max;
    int top;
    T *data;
public:
    Stack(int maxsize=10){
        top=-1;
        max=maxsize-1;
        data=new T[maxsize];
    }
    bool isEmpty(){
        return top==-1;
    }
    bool isFull(){
        return top==max;
    }
    bool push(const T &x){
        if(isFull()){
            cout<<"no memory"<<endl;
            return false;
        }
        data[++top]=x;
        return true;
    }
    T pop(){
        if(isEmpty()){
            cout<<"no element"<<endl;
        }
        T temp=data[top];
        top--;
        return temp;
    }
    T toTop(){
        return data[top];
    }
    void print(){
        if(isEmpty()){
            cout<<"no element"<<endl;
            return;
        }
        else{
            for(int i=0;i<=top;i++){
                cout<<data[i]<<'\t';
            }
            cout<<endl;
        }
    }
};
template <class T>
class LinkedQueue{
private:
    int front;
    int rear;
    int max;
    T *data;
public:
    LinkedQueue<T>(int maxsize=10){
        max=maxsize+1;
        front=rear=0;
        data =new T [max];
    }
    bool IsEmpty(){
        if(front%max==rear%max && front%max==0){
            return true;
        }
        return false;
    }
    bool IsFull(){
        return (rear+1)%max==front%max;
    }
    bool push(int x){
        if(IsFull()){
            cout<<"Full"<<endl;
            return false;
        }
        rear++;
        data[rear]=x;
        return true;
    }
    bool pop(){
        if(IsEmpty()){
            return false;
        }
        front++;
        return true;
    }
    T top(){
        return data[(front+1)%max];
    }
    void Clear(){
        delete [] data;
    }
    void show(){
        for(int i=0;i<(rear-front)%max;i++){
            cout<<data[(front+1+i)%max]<<" ";
        }
        cout<<endl;
    }
};
template <class T>
class MinHeap{
private:
    T *data;
    int m;
    int n;
    int *dataI;
    int *dataJ;
public:
    MinHeap(int sz=100){
        data=new T[sz];
        dataI=new int [sz];
        dataJ=new int [sz];
        m=sz;
        n=0;
    }
    bool Isempty(){
        return n==0;
    }
    bool insertValue(T x,int newI,int newJ){
        if(n==m){
            return false;
        }
        int j=n;
        while(j>0){
            if(data[(j-1)/2]<=x){
                data[j]=x;
                dataI[j]=newI;
                dataJ[j]=newJ;
                n++;
                break;
            }
            else{
                data[j]=data[(j-1)/2];
                dataI[j]=dataI[(j-1)/2];
                dataJ[j]=dataJ[(j-1)/2];
                j=(j-1)/2;
            }
        }
        if(j==0){
            data[j]=x;
            dataI[j]=newI;
            dataJ[j]=newJ;
            n++;
        }
        return true;
    }
    void siftdown(int i){
        //假设i的左右子树已经是最小堆了；
        while(i<=(n-2)/2){
            int left=2*i+1;
            int right=2*i+2;
            if(left>=n && right>=n){
                return;
            }
            if(data[i]<=data[right] && data[i]<=data[left]){
                return;
            }
            else{
                int minnum;
                if(data[left]<data[i]){
                    swap(data[i],data[left]);
                    swap(dataI[i],dataI[left]);
                    swap(dataJ[i],dataJ[left]);
                    minnum=left;
                }
                else if(data[right]<data[i]){
                    swap(data[i],data[right]);
                    swap(dataI[i],dataI[right]);
                    swap(dataJ[i],dataJ[right]);
                    minnum=right;
                }
                siftdown(minnum);
            }
        }
    }
    void initialized(T *a,int sz){
        n=sz;
        for(int i=0;i<n;i++){
            data[i]=a[i];
            dataI[i]=i;
            dataJ[i]=i;
        }
        for(int i=(n-2)/2;i>=0;i--){
            siftdown(i);
        }
    }
    bool DeleteRoot(){
        if(n==1){
            n--;
            delete data;
            return true;
        }
        data[0]=data[n-1];
        dataI[0]=dataI[n-1];
        dataJ[0]=dataJ[n-1];
        n--;
        siftdown(0);
    }
    void show(){
        for(int i=0;i<n;i++){
            cout<<data[i]<<" ";
        }
        cout<<endl;
    }
    T returnRoot(){
        return data[0];
    }
    int returnI(int i){
        return dataI[i];
    }
    int returnJ(int j){
        return dataJ[j];
    }
};
class UFSets{
private:
    int n;
    int *root;
    int *next;
    int *length;
public:
    UFSets(int size){
        n=size;
        for(int i=0;i<n;i++){
            root[i]=next[i]=i;
            length[i]=1;
        }
    }
    int Find(int v){
        return root[v];
    }
    void Union(int v,int u){
        if(root[v]==root[u]){
            return;
        }
        else if(length[root[v]]<length[root[u]]){
            int rt=root[v];//取出v中所有的元素
            length[root[u]]+=length[rt];//修改等价类中u的长度，最后得到的合并集是u
            root[rt]=root[u];//v中所有的元素的代表编号在u中的表达。
            for(int j=next[rt];j!=rt;j=next[j]){
                root[j]=root[u];
            }
            swap(next[rt],next[root[u]]);
        }
        else{
            int rt=root[u];
            length[root[v]]+=length[rt];
            root[rt]=root[v];
            for(int j=next[rt];j!=rt;j=next[j]){
                root[j]=root[v];
            }
            swap(next[rt],next[root[v]]);
        }
    }
};
class Graph{
private:
    float A[6][6];
    bool IsDirected;
    int n;
public:
    Graph(){
        IsDirected= false;
        n=6;
    }
    void createGraph(int size){
        for(int i=0;i<n;i++){
            for(int j=0;i<n;j++){
                A[i][j]=g[i][j];
            }
        }
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(A[i][j]!=A[j][i]){
                    IsDirected=true;
                    return;
                }
            }
        }
    }
    bool returnDirected(){
        return IsDirected;
    }
    bool insertEdge(int i,int j,float w){
        if(i<0 || i>=N || j<0 || j>=N || A[i][j]){
            return false;
        }
        A[i][j]=w;
        A[j][i]=w;
        return true;
    }
    bool delEdge(int i,int j){
        if(i<0 || i>=N || j<0 || j>=N || !A[i][j]){
            return false;
        }
        A[i][j]=0;
        A[j][i]=0;
        return true;
    }
    void visit(int v){
        cout<<"point "<<v<<endl;
    }
    void dfs(int v,bool *flag){
        visit(v);
        flag[v]=1;
        for(int i=0;i<N;i++){
            if(flag[i]==0 && A[v][i]!=INF){
                dfs(i,flag);
            }
        }
    }
    void DFS(int v,bool *flag){
        Stack<int> s(100);
        s.push(v);
        while(!s.isEmpty()){
            visit(v);
            flag[v]=1;
            int i=0;
            for(;i<N;i++){
                if(!flag[i] && A[v][i]!=INF){
                    v=i;
                    visit(v);
                    flag[v]=1;
                    s.push(v);
                    break;
                }
            }
            if(i==N){
                s.pop();s.pop();
            }
        }
    }
    void depthFirstSearch1(int n){
        bool *flag= new bool[N];
        for(int i=0;i<N;i++){
            flag[i]=false;
        }
        dfs(n,flag);
    }
    void depthFirstSearch2(int n){
        bool *flag= new bool[N];
        for(int i=0;i<N;i++){
            flag[i]=false;
        }
        dfs(n,flag);
    }
    void BreathFirstSearch(int n){
        bool *flag= new bool[N];
        for(int i=0;i<N;i++){
            flag[i]= false;
        }
        LinkedQueue<int> que(N);
        que.push(n);
        int v=n;
        while(!que.IsEmpty()){
            v=que.top();
            if(v>=N)
                break;
            que.pop();
            visit(v);
            flag[v]= true;
            for(int i=0;i<N;i++) {
                if (!flag[i] && A[v][i]!=INF) {
                    flag[i] = true;
                    que.push(i);
                }
            }
        }
    }
};
int main() {
    Graph gra;
    gra.createGraph(6);
    if(gra.returnDirected()){
        cout<<"directed graph"<<endl;
    }
    else{
        cout<<"undirected graph"<<endl;
    }
    cout<<"input start point"<<endl;
    int n;
    cin>>n;
    cout<<"dfs1:"<<endl;
    gra.depthFirstSearch1(n);
    cout<<"dfs2:"<<endl;
    gra.depthFirstSearch2(n);
    cout<<"bfs:"<<endl;
    gra.BreathFirstSearch(n);
}

