//maximum sub array sum 2
//O(n*n)
//using cummulative sum array

#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int n,arr[1000],cumSum[1000],i,j,k,maxsum=INT_MIN,first,last;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cumSum[0]=arr[0];
	for(i=1;i<n;i++)
	{
		cumSum[i]=cumSum[i-1]+arr[i];
	}
	for(i=0;i<n;i++)
	{
		for(j=i;j<n;j++)
		{
			int sum=0;
			if(i!=0)
				sum=cumSum[j]-cumSum[i-1];
			else
				sum=cumSum[j];

			if(maxsum<sum)
			{
				maxsum=sum;
				first=i;
				last=j;
			}
		}
	}
	cout<<"Maximum subarray sum is: "<<maxsum<<endl;
	cout<<"Sub array is: ";
	for(i=first;i<=last;i++)
	{
		cout<<arr[i]<<", ";
	}
	return 0;
}