//Quick sort

#include <iostream>

using namespace std;

int partition(int arr[],int first,int last)
{
	int pivot=arr[last];
	int i=first,j=first;
	while(j<last)
	{
		if(arr[j]<pivot)
		{
			swap(arr[j],arr[i]);
			i++;
		}
		j++;
	}
	swap(arr[i],arr[last]);
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

int main()
{
	int arr[6]={1,5,3,0,9,10};
	cout<<"Original array is: ";
	for(int i=0;i<6;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	quickSort(arr,0,5);
	cout<<"Sorted array is: ";
	for(int i=0;i<6;i++)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}