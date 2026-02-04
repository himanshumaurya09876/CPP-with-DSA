//pivot in circular rotated array
#include <iostream>

using namespace std;

int findPivot(int arr[],int n)
{
	int lo=0,hi=n-1;
	while(lo<=hi)
	{
		int mid=lo+(hi-lo)/2;
		if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])
		{
			return mid;
		}
		else if(arr[mid]<arr[hi])
		{
			hi=mid-1;
		}
		else //arr[mid]>arr[lo]
		{
			lo=mid+1;
		}
	}
	return n-1;
}

int main(int argc, char const *argv[])
{
	int n,arr[100],num;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cout<<findPivot(arr,n)<<endl;
	return 0;
}