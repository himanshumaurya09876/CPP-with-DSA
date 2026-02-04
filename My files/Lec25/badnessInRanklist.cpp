//badness in ranklist
#include <iostream>
#include <algorithm>
using namespace std;

int badnessInRanklist(int arr[],int n)
{
	sort(arr,arr+n);
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	int badness=0;
	for(int i=0;i<n;i++)
	{
		int diff=i+1-arr[i];
		if(diff<0)
		{
			diff=-diff;
		}
		badness+=diff;
	}
	return badness;
}

int main(int argc, char const *argv[])
{
	int n,arr[100];
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cout<<badnessInRanklist(arr,n)<<endl;
	return 0;
}