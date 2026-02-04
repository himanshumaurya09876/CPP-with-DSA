//maximum sub array sum 1
//O(n*n*n)
//Bruteforce method

#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int n,arr[1000],i,j,k,maxsum=INT_MIN,first,last;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	for(i=0;i<n;i++)
	{
		for(j=i;j<n;j++)
		{
			int sum=0;
			for(k=i;k<=j;k++)
			{
				sum+=arr[k];
			}
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