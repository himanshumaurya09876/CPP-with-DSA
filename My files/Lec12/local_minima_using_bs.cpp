//local minima using binary search

#include <iostream>

using namespace std;

int binarySearch(int arr[],int first,int last,int n)
{
	int ans=-1;
	while(first<=last)
	{
		int mid=first+(last-first)/2;
		if(((mid==0) || (arr[mid]<arr[mid-1])) && ((arr[mid]<arr[mid+1]) || (mid==n)))
		{
			ans=arr[mid];
			break;
		}
		else if(arr[mid]>arr[mid-1])
		{
			last=mid-1;
		}
		else
		{
			first=mid+1;
		}
	}
	return ans;
}

int main()
{
	int arr[10]={15,4,6,9,15,14,0,8,3,5};
	cout<<binarySearch(arr,0,9,9);
	return 0;
}