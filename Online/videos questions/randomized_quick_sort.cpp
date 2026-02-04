//randomized quick sort to avoid worst case and hence reduce the complexity to O(nlogn)

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void shuffle(int arr[],int first,int last)
{
	int i=last,j;
	srand(time(NULL));
	while(i>first)
	{
		j=rand()%i;//random number is generated with in range of first/0 and i-1 both inclusive
		swap(arr[i],arr[j]);
		i--;
	}
}

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
	shuffle(arr,0,n-1);
	cout<<"Shuffled array is: ";
	for (int i = 0; i < n; ++i)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	quickSort(arr,0,n-1);
	cout<<"Sorted array is: ";
	for (int i = 0; i < n; ++i)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}