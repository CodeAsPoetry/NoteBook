#include<iostream>
#include<cstring>
using namespace std;
#define maxn 10005
#define M 105
int c[M][maxn];   //c[i][j]��ʾǰi����Ʒ��������Ϊj���ﳵ��õ�����ֵ
int w[M],v[M];    //w[i]��ʾ��i����Ʒ��������v[i]��ʾ��i����Ʒ�ļ�ֵ
int x[M];         //x[i]��ʾ��i����Ʒ�Ƿ���빺�ﳵ

int main(){
    int i,j,n,W;     //n��ʾn����Ʒ��W��ʾ���ﳵ������
    cout<<"��������Ʒ�ĸ���n��";
    cin>>n;
    cout<<"�����빺�ﳵ������W��";
    cin>>W;
    cout<<"����������ÿ����Ʒ������w�ͼ�ֵv���ÿո�ֿ���";
    for(i=1;i<=n;i++){
        cin>>w[i]>>v[i];
    }
    for(i=0;i<=n;i++){ //��ʼ����0��Ϊ0
        c[i][0]=0;
    }
    for(j=0;j<=W;j++){ //��ʼ����0��Ϊ0
        c[0][j]=0;
    }
    for(i=1;i<=n;i++){ //����c[i][j]
        for(j=1;j<=W;j++){
            if(j<w[i]){   //����Ʒ���������ڹ��ﳵ���������򲻷Ŵ���Ʒ
                c[i][j] = c[i-1][j];
            }
            else{  //����Ƚϴ���Ʒ���벻���Ƿ���ʹ���ﳵ�ڵļ�ֵ���
                c[i][j] = max(c[i-1][j],c[i-1][j-w[i]]+v[i]);
            }
        }
    }
    cout<<"װ�빺�ﳵ������ֵΪ��"<<c[n][W]<<endl;

    //���������Ž�
    j=W;
    for(i=n;i>0;i--){
        if(c[i][j]>c[i-1][j]){
            x[i] = 1;
            j-=w[i];
        }else{
            x[i] = 0;
        }
    }
    cout<<"װ�빺�ﳵ����ƷΪ��";
    for(i=1;i<=n;i++){
        if(x[i]==1){
            cout<<i<<" ";
        }
    }
    return 0;
}
