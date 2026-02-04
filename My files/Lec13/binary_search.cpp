//binary search

#include <iostream>

using namespace std;

int binarySearch(int arr[],int first,int last,int num)
{
	while(first<=last)
	{
		int mid=(first+last)/2;
		if(num==arr[mid])
		{
			return mid;
		}
		else if(arr[mid]>num)
		{
			last=mid-1;
		}
		else
		{
			first=mid+1;
		}
	}
	return -1;
}

int main()
{
	int arr[10]={1,25,69,70,78,89,100,254,500,659};
	cout<<binarySearch(arr,0,9,99);
	return 0;
}