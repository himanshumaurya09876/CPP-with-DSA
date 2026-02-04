//book allocation problem

#include<iostream>
using namespace std;
bool check(int n,int m,int mid,long long int arr[])
{
    long long int sum=0;
    for(int i=0;i<n;i++)
    {
        if(mid<arr[i])
        {
            return false;
        }
        sum+=arr[i];
        if(sum>mid)
        {
            m--;
            if(m==0)
            {
                return false;
            }
            sum=arr[i];
        }
    }
    return true;
}

long long int findMaxPages(int n,int m,long long int arr[])
{
    long long int low=arr[0],high=0,ans=0;
    for(int i=0;i<n;i++)
    {
        high+=arr[i];
    }
    while(low<=high)
    {
        long long int mid=low+(high-low)/2;
        bool possible=check(n,m,mid,arr);
        if(possible)
        {
            ans=mid;
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    return ans;
} 

int main() {
    int t;
    cin>>t;
    while(t>0)
    {
        int n,m;
        long long int arr[100];
        cin>>n>>m;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        cout<<findMaxPages(n,m,arr);
        t--;
    }
	return 0;
}