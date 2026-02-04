//wave sort
#include <iostream>

using namespace std;

void waveSort(int arr[],int n)
{
	for(int i=0;i<n;i+=2)
	{
		if(arr[i]>arr[i-1] && i!=0)
		{
			swap(arr[i],arr[i-1]);
		}
		if(arr[i]>arr[i+1] && i!=n-1)
		{
			swap(arr[i],arr[i+1]);
		}
	}
}

int main(int argc, char const *argv[])
{
	int arr[100],n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	waveSort(arr,n);
	cout<<"Sorted array is: "<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}