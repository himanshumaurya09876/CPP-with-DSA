#include<iostream>
#include<string>
using namespace std;

int findStrat(int arr[],int f,int l,int sum1=0,int i=1)
{
	if(f>l)
	{
		return sum1;
	}
	if(l&1)
	{
		if(arr[f]>arr[l])
		{
			return findStrat(arr,f+1,l,sum1+arr[f],i+1);
		}
		else if(arr[f]<arr[l])
		{
			return findStrat(arr,f,l-1,sum1+arr[l],i+1);	
		}
		else
		{
			int res1=findStrat(arr,f+1,l,sum1+arr[f],i+1);
			int res2=findStrat(arr,f,l-1,sum1+arr[l],i+1);
			if(res1>res2)
			{
				return res1;
			}
			else
			{
				return res2;
			}
		}
	}
	else
	{
		if(arr[f]>arr[l])
		{
			return findStrat(arr,f+1,l,sum1,i+1);
		}
		else if(arr[f]<arr[l])
		{
			return findStrat(arr,f,l-1,sum1,i+1);	
		}
		else
		{
			int res1=findStrat(arr,f+1,l,sum1,i+1);
			int res2=findStrat(arr,f,l-1,sum1,i+1);	
			if(res1>res2)
			{
				return res1;
			}
			else
			{
				return res2;
			}
		}
	}
}

int main() {
	int n,arr[30];
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cout<<findStrat(arr,0,n-1);
	return 0;
}