//rain water harvesting (trapping)


#include<iostream>
using namespace std;
int findWater(int arr[],int n,int left[],int right[])
{
	int ans=0;
	left[0]=arr[0];
	for(int i=1;i<n;i++)
	{
		if(arr[i]>left[i-1])
		{
			left[i]=arr[i];
		}
		else
		{
			left[i]=left[i-1];
		}
	}
	right[n-1]=arr[n-1];
	for(int i=n-2;i>=0;i--)
	{
		if(arr[i]>right[i+1])
		{
			right[i]=arr[i];
		}
		else
		{
			right[i]=right[i+1];
		}
	}
	for(int i=0;i<n;i++)
	{
		int res=min(left[i],right[i]);
		if(res>arr[i])
		{
			ans+=res-arr[i];
		}
	}
	return ans;
}

int main() {
	int n,arr[100000],left[100000]={0},right[100000]={0};
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cout<<findWater(arr,n,left,right);
	return 0;
}