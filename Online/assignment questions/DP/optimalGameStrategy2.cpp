// OPTIMAL GAME STRATEGY-II
// Piyush and Nimit are playing a coin game. They are given n coins with values x1, x2 …. xn where 'n' is always even. They take alternate terms. In each turn, a player picks either the first coin or the last coin from the row and removes it from the row. The value of coin is received by that player. Determine the maximum value that piyush can win if he moves first. Both the players play optimally.

// Input Format:
// First line contains the number of coins 'n'. Second line contains n space separated integers which is the value of ith coin.

// Constraints:
// N <= 10000

// Output Format
// Print a single line with the maximum possible value.

// Sample Input
// 4
// 1 2 3 4
// Sample Output
// 6

#include <iostream>
using namespace std;
int maxValueBU(int arr[],int n)
{
	int dp[10001][10001];
	
    for(int i=0;i<=n+1;i++)
    {
        for(int j=0;j<=n+1;j++)
        {
            dp[i][j]=0;
        }
    }

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
	return 0;
}