//binary search first occurence for multiple targets in the list

#include <iostream>

using namespace std;

int binarySearch(int arr[],int first,int last,int num)
{
	int ans=-1;
	while(first<=last)
	{
		int mid=(first+last)/2;
		if(num==arr[mid])
		{
			last=mid-1;
			ans=mid;
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
	return ans;
}

int main()
{
	int arr[10]={1,25,65,65,65,65,100,254,500,659};
	cout<<binarySearch(arr,0,9,65);
	return 0;
}