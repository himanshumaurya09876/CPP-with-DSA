#include <iostream>
using namespace std;

int findNum(int arr[],int n,int num)
{
	int first=0,last=n-1;
	while(first<=last)
	{
		int mid=first+(last-first)/2;
		if(arr[mid]==num)
		{
			return mid;
		}
		else if(arr[mid]<arr[last])
		{
			if(arr[mid]<num && num<=arr[last])
			{
				first=mid+1;
			}
			else
			{
				last=mid-1;
			}
		}
		else
		{
			if(arr[mid]>num && num>=arr[first])
			{
				last=mid-1;
			}
			else
			{
				first=mid+1;
			}
		}
	}
	return -1;
}

int main(int argc, char const *argv[])
{
	int n,num;
	cin>>n;
	int *arr=new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cin>>num;
	cout<<findNum(arr,n,num)<<endl;
	return 0;
}