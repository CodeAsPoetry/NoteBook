#include<cstdio>
#include<iostream>
#include<cstring>
#include<windows.h>
#include<stack>
using namespace std;
const int N=100;  //���еĸ������޸�
const int INF = 1e7;   //��ʼ�������Ϊ10000000
int map[N][N],dist[N],p[N],n,m;   //n���еĸ�����mΪ���м�·����������
bool flag[N];   //���flag[i]����true��˵������i�Ѿ����뵽����S�����򶥵�i���ڼ���V-S
void Dijkstra(int u){
    for(int i=1;i<=n;i++){   //1
        dist[i] =map[u][i];  //��ʼ��Դ��u������������������·������
        flag[i] = false;
        if(dist[i]==INF)
            p[i]=-1;  //Դ��u���ö����·������Ϊ�����˵������i��Դ��u������
        else
            p[i]=u;   //˵������i��Դ��u���ڣ����ö���i��ǰ��p[i]=u
    }
    dist[u]=0;
    flag[u]=true;  //��ʼʱ������S��ֻ��һ��Ԫ�أ�Դ��u
    for(int i=1;i<=n;i++){   //2
        int temp = INF,t=u;
        for(int j=1;j<=n;j++){    //3 �ڼ���V-S��Ѱ�Ҿ���Դ��u����Ķ���t
            if(!flag[j]&&dist[j]<temp){
                t=j;
                temp=dist[j];
            }
        }
        if(t==u) return;    //�Ҳ���t,����ѭ��
        flag[t] = true;     //���򣬽�t���뼯��
        for(int j=1;j<=n;j++){       //4 ���¼���V-S����t�ڽӵĶ��㵽Դ��u�ľ���
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
    stack<int>s;  //ջ
    cout<<"ԴͷΪ��"<<u<<endl;
    for(int i=1;i<=n;i++){
        x=p[i];
        while(x!=-1){
            s.push(x);  //��ǰ������ѹ��ջ��
            x=p[x];
        }
        cout<<"Դ�㵽�������������·��Ϊ��";
        while(!s.empty()){
            cout<<s.top()<<"--";  //����ȡջ��Ԫ��
            s.pop();//��ջ
        }
        cout<<i<<";��̾���Ϊ��"<<dist[i]<<endl;
    }

}
int main(){
    int u,v,w,st;
    system("color 0d");
    cout<<"��������еĸ�����"<<endl;
    cin>>n;
    cout<<"���������֮���·�ߵĸ�����"<<endl;
    cin>>m;
    cout<<"���������֮���·���Լ����룺"<<endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            map[i][j]=INF;  //��ʼ���ڽӾ���Ϊ�����
        }
    }
    while(m--){
        cin>>u>>v>>w;
        map[u][v] = min(map[u][v],w);   //�ڽӾ���洢��������С�ľ���
    }
    cout<<"������С�����ڵ�λ�ã�"<<endl;
    cin>>st;
    Dijkstra(st);
    cout<<"С�����ڵ�λ��"<<st<<endl;
    for(int i=1;i<=n;i++){
        cout<<"С����"<<st<<" - "<<"Ҫȥ��λ�ã�"<<i<<endl;
        if(dist[i]==INF){
            cout<<"Sorry����·�ɴ�"<<endl;
        }else{
            cout<<"��̾���Ϊ��"<<dist[i]<<endl;
        }
    }
    findpath(st);
    return 0;




}
