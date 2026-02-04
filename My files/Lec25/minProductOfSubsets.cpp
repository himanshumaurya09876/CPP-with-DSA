#include <iostream>
#include <algorithm>
using namespace std;

int minProductOfSubsets(int arr[],int n)
{
	sort(arr,arr+n);
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	int res=1;
	if(arr[0]==0)
	{
		return 0;
	}
	else if(arr[0]<0)
	{
		int count=0;
		int i=0;
		while(i<n && arr[i]<0)
		{
			count++;
			i++;
		}
		if(count%2)
		{
			for(int i=0;i<n;i++)
			{
				if(arr[i]!=0)
				{
					res*=arr[i];
				}
			}
		}
		else
		{
			for(int i=0;i<n;i++)
			{
				if(arr[i]!=0 && !(arr[i]<0 && arr[i+1]>=0))
				{
					res*=arr[i];
				}
			}
		}
	}
	else
	{
		for(int i=0;i<n;i++)
		{
			res*=arr[i];
		}
	}
	return res;
}

int main(int argc, char const *argv[])
{
	int n,arr[100];
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cout<<minProductOfSubsets(arr,n)<<endl;
	return 0;
}