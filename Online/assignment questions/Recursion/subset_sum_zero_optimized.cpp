//subset sum zero optimized

#include <iostream>

using namespace std;

int isSubsetSumZero(int arr[],int n,int target,int sum=0,int i=0)
{
	//base case
	if(i==n)
	{
		if(sum==target)
			return 1;
		else
			return 0;
	}

	int res=isSubsetSumZero(arr,n,target,sum,i+1)+isSubsetSumZero(arr,n,target,sum+arr[i],i+1);
	return res;
}

int main() {
	int t;
	cin>>t;
	while(t>0)
	{
		int n,arr[10],target=0;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		if(isSubsetSumZero(arr,n,target)>=2)
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