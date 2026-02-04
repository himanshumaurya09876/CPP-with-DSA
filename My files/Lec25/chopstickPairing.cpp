//chopsticks pairing problem
#include <iostream>
#include <algorithm>
using namespace std;

int noOfPairs(int arr[],int n,int d)
{
	int count=0;
	sort(arr,arr+n);
	for(int i=0;i<n-1;i++)
	{
		if(arr[i+1]-arr[i]<=d)
		{
			count++;
			i++;
		}
	}
	return count;
}

int main(int argc, char const *argv[])
{
	int n,arr[100],d;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cin>>d;
	cout<<noOfPairs(arr,n,d)<<endl;
	return 0;
}