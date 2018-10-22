#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 100;
int father[N];
int n,m;
struct Edge{
    int u;
    int v;
    int w;
}e[N*N];

bool comp(Edge x,Edge y){
    return x.w<y.w;   //排序优先级，按边的权值从小到大
}

void Init(int n){
    for(int i=1;i<=n;i++){
        father[i] = i;   //顶点所属集合号。初始化每个顶点一个集合号
    }
}

int Find(int x){     //找祖宗
    if(x!=father[x]){
        father[x] = Find(father[x]);  //把当前结点到其祖宗路径上的所有结点的集合号改为祖宗集合号
    }
    return father[x];   //返回其祖宗的集合号
}

int Merge(int a,int b){   //两结点合并集合号
    int p = Find(a);    //找a的集合号
    int q = Find(b);    //找b的集合号
    if(p==q) return 0;
    if(p>q){
        father[p] = q;   //小的集合号赋值给大的集合号
    }else{
        father[q] = p;
    }
    return 1;
}

int Kruskal(int n){
    int ans = 0;
    for(int i=0;i<m;i++){
        if(Merge(e[i].u,e[i].v)){
            ans += e[i].w;
            n--;
            if(n==1){
                return ans;
            }
        }
    }
    return 0;
}

int main(){
    cout<<"请输入结点数n和边数m："<<endl;
    cin>>n>>m;
    Init(n);
    cout<<"请输入结点数u，v和边值w: "<<endl;
    for(int i=1;i<=m;i++){
        cin>>e[i].u>>e[i].v>>e[i].w;
    }
    sort(e,e+m,comp);
    int ans = Kruskal(n);
    cout<<"最小的花费是："<<ans<<endl;
    return 0;
}
