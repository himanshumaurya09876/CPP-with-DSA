// K-ORDERED LCS
// Any programmer worth his salt would be familiar with the famous Longest Common Subsequence problem. Mancunian was asked to solve the same by an incompetent programmer. As expected, he solved it in a flash. To complicate matters, a twist was introduced in the problem.

// In addition to the two sequences, an additional parameter k was introduced. A k-ordered LCS is defined to be the LCS of two sequences if you are allowed to change atmost k elements in the first sequence to any value you wish to. Can you help Mancunian solve this version of the classical problem?

// Input Format:
// The first line contains three integers N, M and k, denoting the lengths of the first and second sequences and the value of the provided parameter respectively. The second line contains N integers denoting the elements of the first sequence. The third line contains M integers denoting the elements of the second sequence.

// Constraints:
// 1 <= N, M <= 2000 1 <= k <= 5 1 <= element in any sequence <= 109

// Output Format
// Print the answer in a new line.

// Sample Input
// 5 5 1
// 1 2 3 4 5
// 5 3 1 4 2
// Sample Output
// 3

#include <iostream>
#include <cstring>
using namespace std;
int memo[2001][2001][6];

int lcsTD(int arr1[],int arr2[],int n,int m,int k,int i=0,int j=0)
{
	if(i>=n || j>=m)
	{
		return 0;
	}

	if(memo[i][j][k]!=-1)
	{
		return memo[i][j][k];
	}

	int ans=0;
	if(arr1[i]==arr2[j])
	{
		ans=1+lcsTD(arr1,arr2,n,m,k,i+1,j+1);
	}
	else
	{
		if(k>0)
		{
			ans=1+lcsTD(arr1,arr2,n,m,k-1,i+1,j+1);
		}
		ans=max(ans,max(lcsTD(arr1,arr2,n,m,k,i+1,j),lcsTD(arr1,arr2,n,m,k,i,j+1)));
	}
	memo[i][j][k]=ans;
	return ans;
}

int main(int argc, char const *argv[])
{
	int n,m,k;
	cin>>n>>m>>k;
	int *arr1=new int[n];
	int *arr2=new int[m];
	for(int i=0;i<n;i++)
	{
		cin>>arr1[i];
	}
	for(int i=0;i<m;i++)
	{
		cin>>arr2[i];
	}

	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			for(int p=0;p<=k;p++)
			{
				memo[i][j][p]=-1;
			}
		}
	}
	cout<<lcsTD(arr1,arr2,n,m,k)<<endl;
	return 0;
}