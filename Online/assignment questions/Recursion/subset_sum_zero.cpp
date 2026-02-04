//is any subset sum equal to zero
//bruteforce method

#include<iostream>
using namespace std;

bool isSubsetSumZero(int inarr[],int n,int outarr[],int i=0)
{
	//base case
	if(i==n)
	{
		int sum=0;
		char flag='n';
		for(int k=0;k<n;k++)
		{
			if(inarr[k]==0)
				return true;
			sum+=outarr[k];
			if(outarr[k]!=0)
			{
				flag='y';
			}
		}
		if(flag=='y' && sum==0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	//not taken
	outarr[i]=0;
	if(isSubsetSumZero(inarr,n,outarr,i+1))
	{
		return true;
	}
	//taken
	outarr[i]=inarr[i];
	if(isSubsetSumZero(inarr,n,outarr,i+1))
	{
		return true;
	}
	outarr[i]=0;
	return false;
}

int main() {
	int t;
	cin>>t;
	while(t>0)
	{
		int n,arr[10],arr1[10];
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		if(isSubsetSumZero(arr,n,arr1))
		{
			cout<<"Yes"<<endl;
		}
		else
		{
			cout<<"No"<<endl;
		}
		t--;
	}
	return 0;
}
