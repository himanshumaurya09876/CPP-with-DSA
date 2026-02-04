//max circular subarray sum
#include <iostream>
using namespace std;
int maxCircularSum(int arr[],int n)
{
	int maxsum=0,currsum=0;
	for(int i=0;i<n;i++)
	{
		if(currsum<0)
		{
			currsum=0;
		}
		currsum+=arr[i];
		if(maxsum<currsum)
		{
			maxsum=currsum;
		}
	}
	//cout<<maxsum<<endl;
	int totalsum=0;
	for(int i=0;i<n;i++)
	{
		totalsum+=arr[i];
		arr[i]=-arr[i];
	}
	//cout<<totalsum<<endl;
	int maxnegsum=0;
	currsum=0;
	for(int i=0;i<n;i++)
	{
		if(currsum<0)
		{
			currsum=0;
		}
		currsum+=arr[i];
		if(maxnegsum<currsum)
		{
			maxnegsum=currsum;
		}
	}
	//cout<<maxnegsum<<endl;
	int maxcirsum=totalsum+maxnegsum;
	//cout<<maxcirsum<<endl;
	return max(maxsum,maxcirsum);
}
int main() {
	int n,arr[100];
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cout<<maxCircularSum(arr,n);
	return 0;
}