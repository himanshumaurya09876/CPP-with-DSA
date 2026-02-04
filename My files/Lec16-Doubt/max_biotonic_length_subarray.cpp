//max biotonic length subarray
#include <iostream>
using namespace std;
int maxLength(int arr[],int n)
{
	int incArr[100],decArr[100];
	incArr[0]=1;
	decArr[n-1]=1;
	for(int i=1;i<n;i++)
	{
		//increasing array
		if(arr[i]>arr[i-1])
		{
			incArr[i]=incArr[i-1]+1;
		}
		else
		{
			incArr[i]=1;
		}
 
		//decreasing array
		if(arr[n-i]<arr[n-i-1])
		{
			decArr[n-i-1]=decArr[n-i]+1;
		}
		else
		{
			decArr[n-i-1]=1;
		}
	}
	// for(int i=0;i<n;i++)
 
	// {
	// 	cout<<incArr[i]<<" ";
	// }
	//cout<<endl;
	// for(int i=0;i<n;i++)
 
	// {
	// 	cout<<decArr[i]<<" ";
	// }
	// cout<<endl;
	int maxlength=0;
	for(int i=0;i<n;i++)
	{
		int currlength=incArr[i]+decArr[i]-1;
		if(maxlength<currlength)
		{
			maxlength=currlength;
		}
	}
	return maxlength;
}
int main()
{
	int n,arr[100];
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cout<<maxLength(arr,n)<<endl;
	return 0;
}