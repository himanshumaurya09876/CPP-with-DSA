#include <iostream>
#include <algorithm>
using namespace std;
//here greedy is not working so we are taking all possible combinations and then selecting minimum of them

bool compare(int a,int b)
{
	return a>b;
}

int minNoOfCoins(int arr[],int n,int sum,int j=0)
{
	if(sum==0)
	{
		return 0;
	}
	else if(sum<0)
	{
		return -1;
	}
	int minm=INT_MAX;
	for(int i=j;i<n;i++)
	{
		int res1=minNoOfCoins(	arr,n,sum%arr[i],i+1);
		int res2=sum/arr[i];
		if(res1!=-1)
		{
			int res=res1+res2;
			if(minm>res)
			{
				minm=res;
			}
		}
	}
	return minm;
} 

int main(int argc, char const *argv[])
{
	int arr[100],n,sum;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cin>>sum;
	sort(arr,arr+n,compare);
	cout<<minNoOfCoins(arr,n,sum)<<endl;
	return 0;
}