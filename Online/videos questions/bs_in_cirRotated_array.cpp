//binary search in circularly rotated array
#include <iostream>

using namespace std;

int searchNum(int arr[],int n,int num)
{
	int lo=0,hi=n-1;
	while(lo<=hi)
	{
		int mid=lo+(hi-lo)/2;
		if(arr[mid]==num)
		{
			return mid;
		}
		else if(arr[mid]<arr[hi])
		{
			if(arr[mid]<num && num<=arr[hi])
			{
				lo=mid+1;
			}
			else
			{
				hi=mid-1;
			}
		}
		else //arr[mid]>arr[lo]
		{
			if(arr[mid]>num && num>=arr[lo])
			{
				hi=mid-1;
			}
			else
			{
				lo=mid+1;
			}
		}
	}
	return -1;
}

int main(int argc, char const *argv[])
{
	int n,arr[100],num;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cin>>num;
	cout<<searchNum(arr,n,num)<<endl;
	return 0;
}