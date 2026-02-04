//linear search using recursion

#include <iostream>

using namespace std;

int linearSearch(int arr[],int n,int num,int i=0)
{
	if(i==n)
	{
		return -1;
	}
	if(arr[i]==num)
	{
		return i;
	}
	return linearSearch(arr,n,num,i+1);
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
	int idx=linearSearch(arr,n,num);
	if(idx==-1)
		cout<<"Not found..."<<endl;
	else
		cout<<"Found at index = "<<idx<<endl;
	return 0;
}