#include<cstdio>
#include<cstring>
#include<iostream
/**
将矩阵的行和列存储在一维数组p[],m[][]数组用于存储分成的各个子问题的最优值，s[][]数组用于存储各个子问题的决策点，然后
在一个for循环里，将问题分为规模为r的子问题，求每个规模子问题的最优解，得到的m[1][n]就是最小计算量。
**/
using namespace std;
const int msize = 100;
int p[msize];
int m[msize][msize],s[msize][msize];
int n;
void matrixchain(){
    int i,j,r,k;
    memset(m,0,sizeof(m));
    memset(s,0,sizeof(s));
    for(r=2;r<=n;r++){
        for(i=1;i<=n-r+1;i++){
            j=i+r-1;
            m[i][j] = m[i+1][j]+p[i-1]*p[i]*p[j];    //决策为k=i的乘法次数
            s[i][j] = i;        //子问题的最优策略是i
            for(k=i+1;k<j;k++){             //对从i到j的所有决策，求最优值，记录最优策略
                int t = m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                if(t<m[i][j]){
                    m[i][j] = t;
                    s[i][j] = k;
                }
            }
        }
    }
}

void print(int i,int j){
    if(i==j){
        cout<<"A["<<i<<"]";
        return;
    }
    cout<<"(";
    print(i,s[i][j]);
    print(s[i][j]+1,j);
    cout<<")";
}

int main(){
    cout<<"请输入矩阵的个数n：";
    cin>>n;
    int i,j;
    cout<<"请依次输入每个矩阵的行数和最后一个矩阵的列数：";
    for(i=0;i<=n;i++){
        cin>>p[i];
    }
    matrixchain();
    print(1,n);
    cout<<endl;
    cout<<"最小计算量的值为："<<m[1][n]<<endl;
}
