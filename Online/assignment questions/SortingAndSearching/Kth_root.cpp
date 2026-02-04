//Kth root

/*
#include<iostream>
#include<math.h>
using namespace std;

long double expo(int a,int b)
{
    long double res=a;
    for(int i=1;i<b;i++)
    {
        res*=a;
    }
    return res;
}

int main() {
    int t;
    cin>>t;
    while(t>0)
    {
        int k;
        long int n;
        cin>>n>>k;
        int i=0;
        while(expo(i,k)<=n)
        {
            i++;
        }
        i--;
        cout<<i<<endl;
        t--;
    }
    return 0;
}
*/

#include<iostream>
using namespace std;

long double expo(long long int a,long long int b)
{
	if(b==0)
    {
        return 1;
    }
    long double res=1;
	long double sol=expo(a,b/2);
    res=sol*sol;
    if(b&1)
    {
        res*=a;
    }
	return res;
}

long long int KthRoot(long long int n,long long int k)
{
    long long int low=0,high=n,mid,ans=0;//most efficient will be to take high=n/k
    while(low<=high)
    {
        mid=low+(high-low)/2;
        if(expo(mid,k)<=n)//we can also use pow fun in math.h
        {
            ans=mid;
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    return ans;
}

int main() {
	int t;
	cin>>t;
	while(t>0)
	{
		long long int n,k;
		cin>>n>>k;
        long long int res=KthRoot(n,k);
		cout<<res<<endl;
		t--;
	}
	return 0;
}