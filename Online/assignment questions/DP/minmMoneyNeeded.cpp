// MINIMUM MONEY NEEDED
// Cody went to the market to buy some oranges for his N friends. There he finds orange wrapped in packets, with the price of i^th packet as val[i]. Now he wants to buy exactly W kg oranges, so he wants you to teint him what minimum price he should pay to buy exactly W kg oranges. Weight of i^th packet is i kg. If price of i^th packet is -1 then this packet is not available for sale. The market has infinite supply of orange packets.

// Input Format:
// First line of input contains two space separated integers N and W, the number of friend he has and the amount of Oranges in kilograms which he should buy.

// The second line contains W space separated integers in which the i^th^ integer specifies the price of a ‘i’kg apple packet. A value of -1 denotes that the corresponding packet is unavailable

// Constraints:
// 1 <= N,W,val[ ] <= 10^3

// Output Format
// Output a single integer denoting the minimum price Code should pay to get exactly W kg oranges. Else print -1 if it is not possible to fill the bag.

// Sample Input
// 5 5
// 1 2 3 4 5
// Sample Output
// 5


//***************************************************************************************************************************************************


//this is incorrect


// #include <iostream>
// #include <cstring>
// #include <climits>
// using namespace std;
// int count;
// int memo[1005][1005];
// int inf=1000001;

// int minValue(int value[],int s,int idx=0)
// {
// 	count++;
// 	if(s==0)
// 	{
// 		return 0;
// 	}

// 	if(idx>=s)
// 	{
// 		return inf;
// 	}

// 	int ans=minValue(value,s,idx+1);
// 	if(value[idx]!=-1)
// 	{
// 		int num=1;
// 		while(s-num*(idx+1)>=0)
// 		{
// 			ans=min(ans,num*value[idx]+minValue(value,s-num*(idx+1),idx+1));
// 			num++;
// 		}
// 	}

// 	return ans;
// }

// int minValueTD(int value[],int s,int idx=0)
// {
// 	count++;
// 	if(s==0)
// 	{
// 		return 0;
// 	}

// 	if(idx>=s)
// 	{
// 		return inf;
// 	}

// 	if(memo[s][idx]!=-1)
// 	{
// 		return memo[s][idx];
// 	}

// 	int ans=minValueTD(value,s,idx+1);
// 	if(value[idx]!=-1)
// 	{
// 		int num=1;
// 		while(s-num*(idx+1)>=0)
// 		{
// 			ans=min(ans,num*value[idx]+minValueTD(value,s-num*(idx+1),idx+1));
// 			num++;
// 		}
// 	}

// 	memo[s][idx]=ans;

// 	return ans;
// }

// int minValueBU(int value[],int s)
// {
// 	int dp[1005][1005];
// 	for(int i=1;i<=s;i++)
// 	{
// 		dp[0][i]=inf;
// 	}
// 	for(int i=0;i<=s;i++)
// 	{
// 		dp[i][0]=0;
// 	}

// 	for(int i=1;i<=s;i++)
// 	{
// 		for(int j=1;j<=s;j++)
// 		{
// 			int ans=dp[i-1][j];
// 			if(value[i-1]!=-1)
// 			{
// 				int num=1;
// 				while(j-num*(i)>=0)
// 				{
// 					ans=min(ans,num*value[i-1]+dp[i-1][j-i]);
// 					num++;
// 				}
// 			}
// 			dp[i][j]=ans;
// 		}
// 	}

// 	for(int i=0;i<=s;i++)
// 	{
// 		for(int j=0;j<=s;j++)
// 		{
// 			cout<<dp[i][j]<<" ";
// 		}
// 		cout<<endl;
// 	}

// 	return dp[s][s];
// }


// int main()
// {
// 	int n,s;
// 	cin>>n>>s;
// 	int *value=new int[s];
// 	for(int i=0;i<s;i++)
// 	{
// 		cin>>value[i];
// 	}

// 	cout<<minValueBU(value,s)<<endl;

// 	memset(memo,-1,sizeof(memo));
// 	count=0;
// 	cout<<minValueTD(value,s)<<" "<<count<<endl;

// 	count=0;
// 	cout<<minValue(value,s)<<" "<<count<<endl;
// 	return 0;
// }

//*********************************************************************************************************************************************************


//this is correct and best approach


#include <iostream>
#define inf 1e9
using namespace std;

int minValueBU(int value[],int s)
{
	int dp[1005];
	fill(dp,dp+s+1,0);
	for(int i=1;i<=s;i++)
	{
		int ans=inf;
		for(int j=0;j<s;j++)
		{
			if(j+1<=i && value[j]!=-1)
			{
				ans=min(ans,value[j]+dp[i-j-1]);
			}
		}
		dp[i]=ans;
	}

	// for(int i=0;i<s+1;i++)
	// {
	// 	cout<<dp[i]<<" ";
	// }

	return dp[s];
}

int main()
{
	int n,s;
	cin>>n>>s;
	int *value=new int[s];
	for(int i=0;i<s;i++)
	{
		cin>>value[i];
	}
	cout<<minValueBU(value,s)<<endl;
	return 0;
}


//*********************************************************************************************************************************************************


// this is incorrect


// #include <iostream>
// #define inf 1e9
// using namespace std;

// int minValueBU(int value[],int s)
// {
// 	int dp[1005][1005];
// 	for(int i=1;i<=s;i++)
// 	{
// 		dp[0][i]=inf;
// 	}
// 	for(int i=0;i<=s;i++)
// 	{
// 		dp[i][0]=0;
// 	}
	
// 	for(int i=1;i<=s;i++)
// 	{
// 		for(int j=1;j<=s;j++)
// 		{
// 			dp[i][j]=dp[i-1][j];
// 			if(j-i>=0 && value[i-1]!=-1)
// 			{
// 				dp[i][j]=min(dp[i][j],value[i-1]+dp[i-1][j-i]);
// 			}
// 		}
// 	}

// 	for(int i=0;i<=s;i++)
// 	{
// 		for(int j=0;j<=s;j++)
// 		{
// 			cout<<dp[i][j]<<" ";
// 		}
// 		cout<<endl;
// 	}

// 	return dp[s][s];
// }


// int main()
// {
// 	int n,s;
// 	cin>>n>>s;
// 	int *value=new int[s];
// 	for(int i=0;i<s;i++)
// 	{
// 		cin>>value[i];
// 	}
// 	int ans=minValueBU(value,s);
// 	if(ans==inf)
// 	{
// 		cout<<-1<<endl;
// 	}
// 	else
// 	{
// 		cout<<ans<<endl;
// 	}
// 	return 0;
// }
//*********************************************************************************************************************************************************


// this is correct


// #include <iostream>
// using namespace std;
// int inf=1000001;

// int minValueBU(int value[],int s)
// {
// 	int dp[105][105];
// 	for(int i=1;i<=s;i++)
// 	{
// 		dp[0][i]=inf;
// 	}
// 	for(int i=0;i<=s;i++)
// 	{
// 		dp[i][0]=0;
// 	}

// 	for(int i=1;i<=s;i++)
// 	{
// 		for(int j=1;j<=s;j++)
// 		{
// 			int ans=dp[i-1][j];
// 			if(value[i-1]!=-1)
// 			{
// 				int num=1;
// 				while(j-num*(i)>=0)
// 				{
// 					ans=min(ans,num*value[i-1]+dp[i-1][j-num*i]);
// 					num++;
// 				}
// 			}
// 			dp[i][j]=ans;
// 		}
// 	}

// 	for(int i=0;i<=s;i++)
// 	{
// 		for(int j=0;j<=s;j++)
// 		{
// 			cout<<dp[i][j]<<" ";
// 		}
// 		cout<<endl;
// 	}

// 	return dp[s][s];
// }


// int main()
// {
// 	int n,s;
// 	cin>>n>>s;
// 	int *value=new int[s];
// 	for(int i=0;i<s;i++)
// 	{
// 		cin>>value[i];
// 	}
// 	int ans=minValueBU(value,s);
//     if(ans==inf)
//     {
//         cout<<-1<<endl;
//     }
//     else
//     {
//         cout<<ans<<endl;
//     }
// 	return 0;
// }
