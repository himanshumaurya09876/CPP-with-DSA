//Binary search using recursion

#include <iostream>

using namespace std;

int binarySearch(int arr[],int num,int first,int last)
{
	if(first>=last)
	{
		return -1;
	}
	int mid=(first+last)/2;
	if(num<arr[mid])
	{
		last=mid-1;
	}
	else if(num>arr[mid])
	{
		first=mid+1;
	}
	else
	{
		return mid;
	}
	return binarySearch(arr,num,first,last);
}

int main()
{
	int n,arr[100],num;
	cout<<"Enter the size of array: ";
	cin>>n;
	cout<<"Enter the elements of the array:"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cout<<"Enter the number to be searched in the list: ";
	cin>>num;
	int idx=binarySearch(arr,num,0,n-1);
	if(idx==-1)
		cout<<"Not found..."<<endl;
	else
		cout<<"Found at index = "<<idx<<endl;
	return 0;
}