#include <iostream>
using namespace std;

bool compare(int a,int b,bool choice)
{
	if(choice)
	{
		return a<b;
	}
	return a>b;
}

void heapify(int arr[],int n,bool choice=true,int idx=0)//heapification or heapify is to make a heap using distorted heap
{
	int leftidx=2*idx+1;
	int rightidx=2*idx+2;
	int mostPriorityIdx=idx;
	if(leftidx<n && compare(arr[mostPriorityIdx],arr[leftidx],choice))
	{
		mostPriorityIdx=leftidx;
	}
	if(rightidx<n && compare(arr[mostPriorityIdx],arr[rightidx],choice))
	{
		mostPriorityIdx=rightidx;
	}
	if(mostPriorityIdx!=idx)
	{
		swap(arr[mostPriorityIdx],arr[idx]);
		heapify(arr,n,choice,mostPriorityIdx);
	}
}

void heapsort(int arr[],int n,bool choice=true)
{
	//let us form the heap
	for(int i=(n-2)/2;i>=0;i--)
	{
		heapify(arr,n,choice,i);
	}

	//swap and then heapify untill the whole array is sorted
	for(int i=n-1;i>=0;i--)
	{
		swap(arr[0],arr[i]);
		heapify(arr,i,choice);
	}
}

int main(int argc, char const *argv[])
{
	int n,arr[100];
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	heapsort(arr,n,false);//for descending order
	//heapsort(arr,n);//for ascending order
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return 0;
}