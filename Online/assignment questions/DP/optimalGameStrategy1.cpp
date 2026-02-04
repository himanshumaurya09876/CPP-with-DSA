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
#include <cstring>
using namespace std;
int memo[100][100];
int count;

int maxValue(int arr[],int s,int e)
{
	count++;
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

int maxValueTD(int arr[],int s,int e)
{
	count++;
	if(s>e)
	{
		return 0;
	}

	if(memo[s][e]!=-1)
	{
		return memo[s][e];
	}

	//P1 chooses s
	int sq1=arr[s]+maxValueTD(arr,s+2,e);//P2 chooses s+1
	int sq2=arr[s]+maxValueTD(arr,s+1,e-1);//P2 chooses e

	//P1 chooses e
	int sq3=arr[e]+maxValueTD(arr,s+1,e-1);//P2 chooses s
	int sq4=arr[e]+maxValueTD(arr,s,e-2);//P2 chooses e-1

	int ans=max(min(sq1,sq2),min(sq3,sq4));
	memo[s][e]=ans;
	return ans;
}

int maxValueBU(int arr[],int n)
{
	int dp[100][100];
	memset(dp,0,sizeof(dp));

	for(int i=1;i<=n;i++)
	{
		dp[i][i]=arr[i-1];
	}

	for(int i=n-1;i>0;i--)
	{
		for(int j=i+1;j<=n;j++)
		{
			//P1 chooses s
			int sq1=arr[i-1]+dp[i+2][j];//P2 chooses s+1
			int sq2=arr[i-1]+dp[i+1][j-1];//P2 chooses e

			//P1 chooses e
			int sq3=arr[j-1]+dp[i+1][j-1];//P2 chooses s
			int sq4=arr[j-1]+dp[i][j-2];//P2 chooses e-1

			int ans=max(min(sq1,sq2),min(sq3,sq4));
			dp[i][j]=ans;
		}
	}

	return dp[1][n];
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
	cout<<maxValueBU(arr,n)<<endl;
	memset(memo,-1,sizeof(memo));
	count=0;
	cout<<maxValueTD(arr,0,n-1)<<" "<<count<<endl;
	count=0;
	cout<<maxValue(arr,0,n-1)<<" "<<count<<endl;
	return 0;
}