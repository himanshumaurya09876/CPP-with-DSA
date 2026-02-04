//Quick sort
#include <iostream>

using namespace std;

int partition(int arr[],int first,int last)
{
	int pivot=arr[first];//here pivot is taken as first element of the array
	int i=first,j=i;
	while(j<=last)
	{
		if(arr[j]<pivot)
		{
			i++;
			swap(arr[j],arr[i]);
		}
		j++;
	}
	swap(arr[i],arr[first]);
	return i;
}

void quickSort(int arr[],int first,int last)
{
	if(first>=last)
	{
		return;
	}
	int p=partition(arr,first,last);
	quickSort(arr,first,p-1);
	quickSort(arr,p+1,last);
}

int main(int argc, char const *argv[])
{
	int n,arr[100];
	cout<<"Enter the size of array: ";
	cin>>n;
	cout<<"Enter the elements in the array"<<endl;
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
	quickSort(arr,0,n-1);
	cout<<"Sorted array is: ";
	for (int i = 0; i < n; ++i)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}