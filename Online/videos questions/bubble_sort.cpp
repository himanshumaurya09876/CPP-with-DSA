//bubble sort using recursion

#include <iostream>

using namespace std;

void bubbleSort1(int arr[],int n)
{
	if(n==1)
	{
		return;
	}
	for(int i=0;i<n-1;i++)
	{
		if(arr[i]>arr[i+1])
		{
			swap(arr[i],arr[i+1]);
		}
	}
	bubbleSort1(arr,n-1);
}

void bubbleSort2(int arr[],int n,int i=0)
{
	if(n==1)
	{
		return;
	}
	if(i==n-1)
	{
		bubbleSort2(arr,n-1);
		return;
	}
	if(arr[i]>arr[i+1])
	{
		swap(arr[i],arr[i+1]);
	}
	bubbleSort2(arr,n,i+1);
	return;
}

int main()
{
	int n,arr[100];
	cout<<"Enter the size of array: ";
	cin>>n;
	cout<<"Enter the elements of the array:"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	//bubbleSort1(arr,n);
	bubbleSort2(arr,n);
	cout<<"Sorted array is: ";
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}