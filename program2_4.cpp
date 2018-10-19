#include<cstdio>
#include<iostream>
#include<cstring>
#include<windows.h>
#include<stack>
using namespace std;
const int N=100;  //城市的个数可修改
const int INF = 1e7;   //初始化无穷大为10000000
int map[N][N],dist[N],p[N],n,m;   //n城市的个数，m为城市间路线数的条数
bool flag[N];   //如果flag[i]等于true，说明顶点i已经加入到集合S；否则顶点i属于集合V-S
void Dijkstra(int u){
    for(int i=1;i<=n;i++){   //1
        dist[i] =map[u][i];  //初始化源点u到其他各个顶点的最短路径长度
        flag[i] = false;
        if(dist[i]==INF)
            p[i]=-1;  //源点u到该顶点的路径长度为无穷大，说明顶点i与源点u不相邻
        else
            p[i]=u;   //说明顶点i与源点u相邻，设置顶点i的前驱p[i]=u
    }
    dist[u]=0;
    flag[u]=true;  //初始时，集合S中只有一个元素：源点u
    for(int i=1;i<=n;i++){   //2
        int temp = INF,t=u;
        for(int j=1;j<=n;j++){    //3 在集合V-S中寻找距离源点u最近的顶点t
            if(!flag[j]&&dist[j]<temp){
                t=j;
                temp=dist[j];
            }
        }
        if(t==u) return;    //找不到t,跳出循环
        flag[t] = true;     //否则，将t加入集合
        for(int j=1;j<=n;j++){       //4 更新集合V-S中与t邻接的顶点到源点u的距离
            if(!flag[j]&&map[t][j]<INF){
                if(dist[j]>(dist[t]+map[t][j])){
                    dist[j]=dist[t]+map[t][j];
                    p[j]=t;
                }
            }

        }
    }

}

void findpath(int u){
    int x;
    stack<int>s;  //栈
    cout<<"源头为："<<u<<endl;
    for(int i=1;i<=n;i++){
        x=p[i];
        while(x!=-1){
            s.push(x);  //将前驱依次压入栈中
            x=p[x];
        }
        cout<<"源点到其他各顶点最短路径为：";
        while(!s.empty()){
            cout<<s.top()<<"--";  //依次取栈顶元素
            s.pop();//出栈
        }
        cout<<i<<";最短距离为："<<dist[i]<<endl;
    }

}
int main(){
    int u,v,w,st;
    system("color 0d");
    cout<<"请输入城市的个数："<<endl;
    cin>>n;
    cout<<"请输入城市之间的路线的个数："<<endl;
    cin>>m;
    cout<<"请输入城市之间的路线以及距离："<<endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            map[i][j]=INF;  //初始化邻接矩阵为无穷大
        }
    }
    while(m--){
        cin>>u>>v>>w;
        map[u][v] = min(map[u][v],w);   //邻接矩阵存储，保留最小的距离
    }
    cout<<"请输入小明所在的位置："<<endl;
    cin>>st;
    Dijkstra(st);
    cout<<"小明所在的位置"<<st<<endl;
    for(int i=1;i<=n;i++){
        cout<<"小明："<<st<<" - "<<"要去的位置："<<i<<endl;
        if(dist[i]==INF){
            cout<<"Sorry，无路可达"<<endl;
        }else{
            cout<<"最短距离为："<<dist[i]<<endl;
        }
    }
    findpath(st);
    return 0;




}
