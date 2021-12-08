#include <iostream>
#include <vector>
#include <cstring>
#define INF 1000000
using namespace std;
int N=6;
float g[6][6] = {{0, 7, 4, 1, 2, INF},
                 {7,0,3,5,INF,4},
                 {4,3,0,INF,9,8},
                 {INF,INF,INF,0,INF,7},
                 {11,INF,9,INF,0,10},
                 {INF,4,3,INF,1,0}
};
class UFSets{
private:
    int n;
    int *root;
    int *next;
    int *length;
public:
    UFSets(int size){
        this->n=size;
        root=new int [n];
        next=new int [n];
        length=new int [n];
        for(int i=0;i<N;i++){
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
        cout<<n<<endl;
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
    float returnNumber(int i,int j){
        return A[i][j];
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
    void prim(int begin){
        int index=begin;
        int i=0;
        int j=0;
        cout<<index<<" ";
        bool visited[N];
        float *dist=new float [N];
        memset(visited, false,sizeof(visited));
        visited[begin]=true;
        for(i=0;i<N;i++){
            dist[i]=A[begin][i];
        }
        for(i=1;i<N;i++){
            float temp=INF;
            for(j=0;j<N;j++){
                if(!visited[j] && dist[j]<temp){
                    temp=dist[j];
                    index=j;
                }
            }
            visited[index]=true;
            cout<<index<<" ";
            for(j=0;j<N;j++){
                if(!visited[j] && dist[j]>A[index][j]){
                    dist[j]=A[index][j];
                }
            }
        }
        cout<<endl;
    }
    void Kruskal(){
        UFSets set(N);
        MinHeap<float> h(N*N);
        int *pointI=new int [N-1];
        int *pointJ=new int [N-1];
        auto *value=new float [N-1];
        for(int i=0;i<N;i++){
            for(int j=i;j<N;j++){
                if(A[i][j]!=INF){
                    h.insertValue(A[i][j],i,j);
                }
            }
        }
        int num=0;
        while(num<N-1){
            if(!h.Isempty()){
                int temp=h.returnRoot();
                int i=h.returnI(0);
                int j=h.returnJ(0);
                h.DeleteRoot();
                if(set.Find(i)!=set.Find(j)){
                    set.Union(i,j);
                    pointI[num]=i;
                    pointJ[num]=j;
                    value[num++]=temp;
                }
            }
            else{
                cout<<"不能生成最小生成树"<<endl;
                return;
            }
        }
        for(int i=0;i<N-1;i++){
            cout<<pointI[i]<<" "<<pointJ[i]<<" "<<value[i]<<endl;
        }
    }
    void Dijkstra(int s){
        auto *dist =new float [N*N];
        bool *visited =new bool [N*N];
        for(int i=0;i<N;i++){
            dist[i]=INF;
        }
        for(int i=0;i<N;i++){
            int index=-1;
            dist[s]=0;
            for(int j=0;j<N;j++){
                if(!visited[j] && (index==-1 || dist[j]<dist[index])){
                    index=j;
                }
            }
            visited[index]= true;
            for(int j=0;j<N;j++){
                if(dist[index]+A[index][j]<dist[j]){
                    dist[j]=dist[index]+A[index][j];
                }
            }
        }
        if(dist[N-1]==INF){
            cout<<"无最短路径"<<endl;
        }
        else{
            for(int i=0;i<N;i++){
                cout<<dist[i]<<" ";
            }
            cout<<endl;
        }
    }
    void Dijkstra2(int v0,float *D,int *path){
        bool *visited = new bool [N];
        for(int i=0;i<N;i++){
            visited[i]= false;
        }
        visited[v0]=true;
        for(int i=0;i<N;i++){
            D[i]=A[v0][i];
            path[i]=v0;
        }
        for(int j=0;j<N-1;j++){
            int min=INF;
            int u=0;
            for(int i=0;i<N;i++){
                if(min>D[i] && !visited[i]){
                    min=D[i];
                    u=i;
                }
            }
            visited[u]=true;
            for(int i=0;i<N;i++){
                if(D[i]>D[u]+A[u][i] && !visited[i]){
                    D[i]=D[u]+A[u][i];
                    path[i]=u;
                }
            }
        }
        for(int i=0;i<N;i++){
            cout<<D[i]<<" ";
        }
        cout<<endl;
    }
    void Floyd(int s){
        int **path= new int *[N];
        for(int i=0;i<N;i++){
            path[i]=new int [N];
        }
        float **adj= new float *[N];
        for(int i=0;i<N;i++){
            adj[i]=new float [N];
        }
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(i==j){
                    path[i][j]=i;
                }
                else{
                    path[i][j]=-1;
                }
                adj[i][j]=A[i][j];
            }
        }
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                for(int k=0;k<N;k++){
                    if(adj[j][k]>adj[j][i]+adj[i][k]){
                        adj[j][k]=adj[j][i]+adj[i][k];
                        path[j][k]=i;
                    }
                }
            }
        }
        for(int i=0;i<N;i++){
            cout<<adj[s][i]<<" ";
        }
        cout<<endl;
    }
};
int main() {
    Graph gra;
    gra.createGraph(N);
    cout<<"Prim:"<<endl;
    gra.prim(0);
    cout<<"Kruskal:"<<endl;
    gra.Kruskal();
    float *D = new float [N];
    int *path = new int [N];
    cout<<"start point:"<<endl;
    int num;
    cin>>num;
    cout<<"Dijkstra1:"<<endl;
    gra.Dijkstra(num);
    for(int i=0;i<N;i++){
        D[i]=gra.returnNumber(num,i);
    }
    cout<<"Dijkstra2:"<<endl;
    gra.Dijkstra2(num,D,path);
    cout<<"Floyd:"<<endl;
    gra.Floyd(num);
}

