#include <iostream>
#include <algorithm>
const int N = 1000005;
using namespace std;
double w[N]; //�Ŷ�����������

int main()
{
    double c;
    int n;
    cout<<"������������c���Ŷ�����n��"<<endl;
    cin>>c>>n;
    cout << "������ÿ���Ŷ����������ÿո�ֿ���" << endl;
    for(int i=0;i<n;i++){
        cin>>w[i];    //����ÿ����Ʒ����
    }
    sort(w,w+n);     //���Ŷ�������������
    double temp = 0.0;
    int ans = 0; // tmpΪ��װ�ص����ϵĹŶ�������ansΪ��װ�صĹŶ�����
    for(int i=0;i<n;i++){
        temp+=w[i];
        if(temp<=c)
            ans ++;
        else
        break;
    }
    cout<<"��װ��ĹŶ��������ΪAns=" << endl;
    cout<<ans<<endl;
    return 0;
}
