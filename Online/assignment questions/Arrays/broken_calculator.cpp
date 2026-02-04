//large factorials ---Broken calculator

#include<iostream>
using namespace std;
int calFact(int n,int ans[])
{
    int res=1,s=99999,rem=0;
    ans[s]=1;
    while(n>0)
    {
        for(int j=99999;j>=s;j--)
        {
            res=ans[j]*n+rem;
            ans[j]=res%10;
            rem=res/10;
        }
        while(rem!=0)
        {
            s--;
            ans[s]=rem%10;
            rem/=10;
        }
        n--;
    }
    return s;
}
int main() {
    int n,ans[100000]={0};
    cin>>n;
    int s=calFact(n,ans);
    for(int i=s;i<100000;i++)
    {
        cout<<ans[i];
    }
	return 0;
}