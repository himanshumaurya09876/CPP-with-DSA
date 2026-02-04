// OPTIMAL GAME STRATEGY-I
// Piyush and Nimit are playing a coin game. They are given n coins with values x1, x2 …. xn where 'n' is always even. They take alternate terms. In each turn, a player picks either the first coin or the last coin from the row and removes it from the row. The value of coin is received by that player. Determine the maximum value that piyush can win if he moves first. Both the players play optimally.

// Input Format:
// First line contains the number of coins 'n'. Second line contains n space separated integers which is the value of ith coin.

// Constraints:
// N < 30

// Output Format
// Print a single line with the maximum possible value.

// Sample Input
// 4
// 1 2 3 4
// Sample Output
// 6

#include <iostream>
using namespace std;

int dp[50][50];

int maxValue(int arr[],int j,int i=0)
{
	if(i>j)
	{
		return 0;
	}

	if(dp[i][j]!=-1)
	{
		return dp[i][j];
	}
	int q1=0,q2=0,q3=0,q4=0;
	int first=0,last=0;
	//he picks the fist coin

	q1=arr[i+1]+maxValue(arr,j,i+2);
	q2=arr[j]+maxValue(arr,j-1,i+1);
	if(q1>q2)
		first=arr[i]+maxValue(arr,j,i+2);
	else
		first=arr[i]+maxValue(arr,j-1,i+1);

	//he picks the last coin

	q3=arr[i]+maxValue(arr,j-1,i+1);
	q4=arr[j-1]+maxValue(arr,j-2,i);
	if(q3>q4)
		last=arr[j]+maxValue(arr,j-1,i+1);
	else
		last=arr[j]+maxValue(arr,j-2,i);

	dp[i][j]=max(first,last);
	return dp[i][j];
}

int main(int argc, char const *argv[])
{
	int n,arr[30];
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			dp[i][j]=-1;
		}
	}
	cout<<maxValue(arr,n-1)<<endl;
	return 0;
}


// //optimal game strategy - 1

// #include<iostream>
// using namespace std;

// int findStrat(int arr[],int f,int l,int sum1=0,int i=1)
// {
// 	if(f>l)
// 	{
// 		return sum1;
// 	}
// 	if(l&1)
// 	{
// 		if(arr[f]>arr[l])
// 		{
// 			sum1+=arr[f];
// 			return findStrat(arr,f+1,l,sum1,i+1);
// 		}
// 		else
// 		{
// 			sum1+=arr[l];
// 			return findStrat(arr,f,l-1,sum1,i+1);	
// 		}
// 	}
// 	else
// 	{
// 		if(arr[f]>arr[l])
// 		{
// 			return findStrat(arr,f+1,l,sum1,i+1);
// 		}
// 		else
// 		{
// 			return findStrat(arr,f,l-1,sum1,i+1);	
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

// //optimal game strategy-1

// #include<iostream>
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