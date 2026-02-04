//sum of two arrays

#include<iostream>
using namespace std;
long long int sumOfArray(long long int arr1[],long long int n1,long long int arr2[],long long int n2,long long int sum[])
{
    long long int s=10000,rem=0,res;
    s--;
    n1--;
    n2--;
    while(n1>=0 && n2>=0)
    {
        res=arr1[n1--]+arr2[n2--]+rem;
        sum[s--]=res%10;
        rem=res/10;
    }
    while(n1>=0)
    {
        res=arr1[n1--]+rem;
        sum[s--]=res%10;
        rem=res/10;
    }
    while(n2>=0)
    {
        res=arr2[n2--]+rem;
        sum[s--]=res%10;
        rem=res/10;
    }
    while(rem!=0)
    {
        sum[s--]=rem%10;
        rem/=10;
    }
    return s+1;
}
int main() {
    long long int n1,n2,arr1[1000],arr2[1000],sum[10000]={0};
    cin>>n1;
    for(long long int i=0;i<n1;i++)
    {
        cin>>arr1[i];
    }
    cin>>n2;
    for(long long int i=0;i<n2;i++)
    {
        cin>>arr2[i];
    }
    long long int s=sumOfArray(arr1,n1,arr2,n2,sum);
    for(long long int i=s;i<10000;i++)
    {
        cout<<sum[i]<<", ";
    }
    cout<<"END";
	return 0;
}