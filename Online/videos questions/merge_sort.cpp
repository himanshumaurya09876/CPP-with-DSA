//merge sort
#include <iostream>

using namespace std;

void merge(int arr[],int first,int mid,int last)
{
	int temp[100],i=first,j=mid+1,k=first;
	while(i<=mid && j<=last)
	{
		if(arr[i]<arr[j])
		{
			temp[k++]=arr[i++];
		}
		else
		{
			temp[k++]=arr[j++];
		}
	}
	while(i<=mid)
	{
		temp[k++]=arr[i++];
	}
	while(j<=last)
	{
		temp[k++]=arr[j++];
	}
	for(i=first;i<=last;i++)
	{
		arr[i]=temp[i];
	}
}

void mergeSort(int arr[],int first,int last)
{
	if(first>=last)
	{
		return;
	}
	int mid=(first+last)/2;
	mergeSort(arr,first,mid);
	mergeSort(arr,mid+1,last);
	merge(arr,first,mid,last);
}

int main()
{
	int n,arr[100];
	cout<<"Enter the size of array: ";
	cin>>n;
	cout<<"Enter the elements in the array"<<endl;
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
	mergeSort(arr,0,n-1);
	cout<<"Sorted array is: ";
	for (int i = 0; i < n; ++i)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}