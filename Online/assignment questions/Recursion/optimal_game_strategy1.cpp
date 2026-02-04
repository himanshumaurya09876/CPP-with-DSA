// //optimal game strategy-1

// #include<iostream>
// #include<string>
// using namespace std;

// int findStrat(int arr[],int f,int l,int sum1=0,int sum2=0,int i=1)
// {
// 	if(f>l)
// 	{
// 		if(sum1>sum2)
// 			return sum1;
// 		else
// 			return sum2;
// 	}
// 	if(l&1)
// 	{
// 		if(arr[f]>arr[l])
// 		{
// 			return findStrat(arr,f+1,l,sum1+arr[f],sum2,i+1);
// 		}
// 		else
// 		{
// 			return findStrat(arr,f,l-1,sum1+arr[l],sum2,i+1);	
// 		}
// 	}
// 	else
// 	{
// 		if(arr[f]>arr[l])
// 		{
// 			return findStrat(arr,f+1,l,sum1,sum2+arr[f],i+1);
// 		}
// 		else
// 		{
// 			return findStrat(arr,f,l-1,sum1,sum2+arr[l],i+1);	
// 		}
// 	}
// }

// int main() {
// 	int n,arr[30];
// 	cin>>n;
// 	for(int i=0;i<n;i++)
// 	{
// 		cin>>arr[i];
// 	}
// 	cout<<findStrat(arr,0,n-1);
// 	return 0;
// }

#include <iostream>
using namespace std;

int maxValue(int arr[],int s,int e)
{
	if(s>e)
	{
		return 0;
	}

	//P1 chooses s
	int sq1=arr[s]+maxValue(arr,s+2,e);//P2 chooses s+1
	int sq2=arr[s]+maxValue(arr,s+1,e-1);//P2 chooses e

	//P1 chooses e
	int sq3=arr[e]+maxValue(arr,s+1,e-1);//P2 chooses s
	int sq4=arr[e]+maxValue(arr,s,e-2);//P2 chooses e-1

	int ans=max(min(sq1,sq2),min(sq3,sq4));
	return ans;
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int *arr=new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cout<<maxValue(arr,0,n-1)<<endl;
	return 0;
} 