#include<iostream>
using namespace std;
int Partition(int r[],int low,int high){          //划分函数
    int i=low,j=high,pivot=r[low];
    while(i<j){
        while(i<j&&r[j]>pivot) j--;         //向左扫描
        if(i<j){
            swap(r[i++],r[j]);              //r[i]和r[j]交换后i右移一位
        }
        while(i<j&&r[i]<=pivot) i++;        //向右扫描
        if(i<j){
            swap(r[i],r[j--]);              //r[i]和r[j]交换后j左移一位
        }
    }
    return i;                //返回最终划分完成后基准元素所在的位置
}

//优化后的快速排序算法
int Partition2(int r[],int low,int high){    //划分函数
    int i=low,j=high,pivot=r[low];   //基准元素
    while(i<j){
        while(i<j &&r[j]>pivot)   j--;         //向左扫描
        while(i<j &&r[i]<=pivot)  i++;         //向右扫描
        if(i<j){
            swap(r[i++],r[j--]);    //r[i]和r[j]交换，交换后i++，j--
        }
    }
    if(r[i]>pivot){
        swap(r[i-1],r[low]);     //r[i-1]和r[low]交换
        return i-1;         //返回最终划分完成后基准元素所在的位置
    }
    swap(r[i],r[low]);      //r[i]和r[low]交换
    return i;     //返回最终划分完成后基准元素所在的位置
}




void QuickSort(int R[],int low,int high){        //快速排序递归算法
    int mid;
    if(low<high){
        mid = Partition2(R,low,high);           //基准位置
        QuickSort(R,low,mid-1);                //左区间递归快速排序
        QuickSort(R,mid+1,high);               //右区间递归快速排序
    }
}

int main(){
    int a[1000];
    int i,N;
    cout<<"请先输入要排序的数据的个数：";
    cin>>N;
    cout<<"请输入要排序的数据：";
    for(i=0;i<N;i++){
        cin>>a[i];
    }
    cout<<endl;
    QuickSort(a,0,N-1);
    cout<<"排序后的序列为："<<endl;
    for(i=0;i<N;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}

