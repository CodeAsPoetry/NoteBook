#include<cstdio>
#include<cstring>
#include<iostream
/**
��������к��д洢��һά����p[],m[][]�������ڴ洢�ֳɵĸ��������������ֵ��s[][]�������ڴ洢����������ľ��ߵ㣬Ȼ��
��һ��forѭ����������Ϊ��ģΪr�������⣬��ÿ����ģ����������Ž⣬�õ���m[1][n]������С��������
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
            m[i][j] = m[i+1][j]+p[i-1]*p[i]*p[j];    //����Ϊk=i�ĳ˷�����
            s[i][j] = i;        //����������Ų�����i
            for(k=i+1;k<j;k++){             //�Դ�i��j�����о��ߣ�������ֵ����¼���Ų���
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
    cout<<"���������ĸ���n��";
    cin>>n;
    int i,j;
    cout<<"����������ÿ����������������һ�������������";
    for(i=0;i<=n;i++){
        cin>>p[i];
    }
    matrixchain();
    print(1,n);
    cout<<endl;
    cout<<"��С��������ֵΪ��"<<m[1][n]<<endl;
}
