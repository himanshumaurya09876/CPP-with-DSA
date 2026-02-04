//maximum sub array sum 3
//Most efficient 
//O(n)
//Kadane's algo

#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int n,arr[1000],i,cumSum=INT_MIN,maxSum=INT_MIN,first,last;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	for(i=0;i<n;i++)
	{
		int temp;
		if(cumSum<0)
		{
			temp=i;
			cumSum=0;
		}
		cumSum+=arr[i];
		if(maxSum<cumSum)
		{
			maxSum=cumSum;
			first=temp;
			last=i;
		}
	}
	cout<<"Maximum subarray sum is: "<<maxSum<<endl;
	cout<<"Sub array is: ";
	for(i=first;i<=last;i++)
	{
		cout<<arr[i]<<", ";
	}
	return 0;
}