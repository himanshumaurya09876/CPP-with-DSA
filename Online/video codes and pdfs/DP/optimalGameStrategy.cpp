#include <iostream>
#include <cstring>
using namespace std;
int memo[1000][1000];
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
	for(int i=0;i<=n+1;i++)
	{
		for(int j=0;j<=n+1;j++)
		{
			if(i==j && i<=n && i>0)
			{
				dp[i][j]=arr[i-1];
			}
			else
			{
				dp[i][j]=0;
			}
		}
	}
	for(int i=n-1;i>0;i--)
	{
		for(int j=i+1;j<=n;j++)
		{
			dp[i][j]=max(arr[i-1]+min(dp[i+2][j],dp[i+1][j-1]),arr[j-1]+min(dp[i+1][j-1],dp[i][j-2]));
		}
	}

	for(int i=0;i<=n+1;i++)
	{
		for(int j=0;j<=n+1;j++)
		{
			cout<<dp[i][j]<<"  ";
		}
		cout<<endl;
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
	cout<<maxValueTD(arr,0,n-1)<<"  "<<count<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<memo[i][j]<<"  ";
		}
		cout<<endl;
	}
	count=0;
	cout<<maxValue(arr,0,n-1)<<"  "<<count<<endl;
	return 0;
} 