#include<iostream>
#include<cstring>
using namespace std;
const int N=100;
char str1[N],str2[N];
int d[N][N];    //d[i][j]表示str1前i个字符和str2前j个字符的编辑距离

int min(int a,int b){
    return a<b?a:b;   //返回较小的值
}

int editdistance(char *str1,char *str2){
    int len1 = strlen(str1);   //计算字符串长度
    int len2 = strlen(str2);
    for(int i=0;i<=len1;i++){  //当第二个串长度为0，编辑距离初始化为i
        d[i][0] = i;
    }
    for(int j=0;j<=len2;j++){  //当第一个串长度为0，编辑距离初始化为j
        d[0][j] = j;
    }
    for(int i=1;i<=len1;i++){  //遍历两个字符串
        for(int j=1;j<=len2;j++){
            int diff;   //判断str[i]是否等于str2[j],相等为0，不相等为1
            if(str1[i-1] == str2[j-1])  //相等
                diff = 0;
            else
                diff = 1;
            int temp = min(d[i-1][j]+1,d[i][j-1]+1);   //先两者取最小值
            d[i][j] = min(temp,d[i-1][j-1]+diff);      //再取最小值
        }
    }
    return d[len1][len2];
}

int main(){
    cout<<"输入字符串str1："<<endl;
    cin>>str1;
    cout<<"输入字符串str2："<<endl;
    cin>>str2;
    cout<<str1<<"和"<<str2<<"的编辑距离是："<<editdistance(str1,str2);
    return 0;
}
