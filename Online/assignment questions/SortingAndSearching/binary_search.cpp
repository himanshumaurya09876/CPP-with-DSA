#include<iostream>
using namespace std;

int binarySearch(int arr[1000000000],int n,int m)
{
	int first=0,last=n-1,mid;
	while(first<=last)
	{
		mid=(first+last)/2;
		if(m>arr[mid])
		{
			first=mid+1;
		}
		else if(m<arr[mid])
		{
			last=mid-1;
		}
		else 
		{
			return mid;
		}
	}
	if(first>last)
	{
		return -1;
	}
}

int main() {
	int  n,arr[1000000000],m;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cin>>m;
	int idx=binarySearch(arr,n,m);
	cout<<idx;
	return 0;
}