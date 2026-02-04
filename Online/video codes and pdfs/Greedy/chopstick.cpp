#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
	int n,k;
	cin>>n>>k;
	int *arr=new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	sort(arr,arr+n);
	int count=0;
	for(int i=0;i<n-1;i++)
	{
		if(arr[i+1]-arr[i]<=k)
		{
			cout<<arr[i]<<"<-->"<<arr[i+1]<<endl;
			count++;
			i++;
		}
	}
	cout<<count<<endl;
	return 0;
}