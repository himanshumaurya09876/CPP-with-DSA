#include<iostream>
using namespace std;

void selectionSort(int arr[100],int n)
{
    int minidx;
	for(int i=0;i<n-1;i++)
    {
        minidx=i;
		for(int j=i+1;j<n;j++)
        {
            if(arr[minidx]>arr[j])
            {
                minidx=j;
            }
        }
		int temp=arr[minidx];
        arr[minidx]=arr[i];
        arr[i]=temp;
    }
}

int main() {
    int n;
    cin>>n;
    int arr[100];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    selectionSort(arr,n);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<endl;
    }
	return 0;
}