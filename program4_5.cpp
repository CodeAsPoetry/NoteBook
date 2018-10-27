#include<iostream>
#include<sstream>
#include<cmath>
#include<algorithm>
using namespace std;
const int M = 1000+5;
int n;
int s[M][M];
double m[M][M],g[M][M];

void Convexpolygontriangulation(){
    for(int i=1;i<=n;i++){           //初始化
        m[i][i] = 0;
        s[i][i] = 0;
    }
    for(int d=2;d<=n;d++){             //d为问题规模，d=2时，实际上是三个点，因为我们的m[i][j]表示的是{vi-1,vi,vj}
        for(int i=1;i<=n-d+1;i++){     //控制i值
            int j = i+d-1;            //j值
            m[i][j] = m[i+1][j] + g[i-1][i] + g[i][j] + g[i-1][j];
            s[i][j] = i;
            for(int k=i+1;k<j;k++){        //枚举划分点
                double temp = m[i][k]+m[k+1][j]+g[i-1][k]+g[k][j]+g[i-1][j];
                if(m[i][j]>temp){
                    m[i][j] = temp;          //更新最优值
                    s[i][j] = k;             //记录划分点
                }
            }
        }
    }

}

void print(int i,int j){              //输出所有的弦
    if(i==j) return;
    if(s[i][j]>1)
        cout<<"{v"<<i-1<<"v"<<s[i][j]<<"}"<<endl;
    if(j>s[i][j]+1)
        cout<<"{v"<<s[i][j]<<"v"<<j<<"}"<<endl;
    print(i,s[i][j]);
    print(s[i][j]+1,j);
}

int main(){
    int i,j;
    cout<<"请输入顶点的个数n：";
    cin>>n;
    n--;
    cout<<"请依次输入各顶点的连接权值：";
    for(i=0;i<=n;++i){              //输入各个顶点之间的连接权值
        for(j=0;j<=n;++j){
            cin>>g[i][j];
        }
    }
    Convexpolygontriangulation();
    cout<<m[1][n]<<endl;
    print(1,n);             //打印路径
    return 0;
}
