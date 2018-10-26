#include<iostream>
using namespace std;
const int ms = 1000;
int r[ms][ms],m[ms][ms],s[ms][ms];    //i到j站的租金
int n;      //共有n个站点
void rent(){
    int i,j,k,d;
    for(d=3;d<=n;d++){     //将问题分为小规模为d
        for(i=1;i<=n-d+1;i++){
            j=i+d-1;
            for(k=i+1;k<j;k++){
                int temp;
                temp = m[i][k]+m[k][j];
                if(temp<m[i][j]){
                    m[i][j]=temp;
                    s[i][j]=k;
                }
            }
        }
    }
}

void print(int i,int j){
    if(s[i][j]==0){
        cout<<"--"<<j;
        return ;
    }
    print(i,s[i][j]);
    print(s[i][j],j);
}

int main(){
    int i,j;
    cout<<"请输入站点的个数n：";
    cin>>n;
    cout<<"请依次输入各站点之间的租金：";
    for(i=1;i<=n;i++){
        for(j=i+1;j<=n;++j){
            cin>>r[i][j];
            m[i][j] = r[i][j];
        }
    }
    rent();
    cout<<"花费的最少租金为："<<m[1][n]<<endl;
    cout<<"最少租金经过的站点："<<1;
    print(1,n);
    return 0;
}
