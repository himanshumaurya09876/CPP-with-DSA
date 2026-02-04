#include <iostream>
#include <string>
using namespace std;
int memo[100][100];
int count;

int editDist(string input,string output,int i=0,int j=0)//recursive
{
	count++;
	if(input[i]=='\0')
	{
		return output.length()-j;//insertion
	}
	if(output[j]=='\0')
	{
		return input.length()-i;//deletion
	}

	int ans=0;
	if(input[i]==output[j])
	{
		ans=editDist(input,output,i+1,j+1);
	}
	else
	{
		//replacement
		int q1=1+editDist(input,output,i+1,j+1);

		//deletion
		int q2=1+editDist(input,output,i+1,j);

		//insertion
		int q3=1+editDist(input,output,i,j+1);

		ans=min(q1,min(q2,q3));
	}

	return ans;
}

int editDistTD(string input,string output,int i=0,int j=0)//top down DP
{
	count++;
	if(input[i]=='\0')
	{
		return output.length()-j;//insertion
	}
	if(output[j]=='\0')
	{
		return input.length()-i;//deletion
	}

	if(memo[i][j]!=-1)
	{
		return memo[i][j];
	}

	int ans=0;
	if(input[i]==output[j])
	{
		ans=editDistTD(input,output,i+1,j+1);
	}
	else
	{
		//replacement
		int q1=1+editDistTD(input,output,i+1,j+1);

		//deletion
		int q2=1+editDistTD(input,output,i+1,j);

		//insertion
		int q3=1+editDistTD(input,output,i,j+1);

		ans=min(q1,min(q2,q3));
	}
	memo[i][j]=ans;
	return ans;
}

int editDistBU(string input,string output)
{
	int li=input.length();
	int lo=output.length();

	int **dp=new int*[li+1];
	for(int i=0;i<=li;i++)
	{
		dp[i]=new int[lo+1];
	}

	dp[0][0]=0;
	for(int i=1;i<=lo;i++) dp[0][i]=dp[0][i-1]+1;
	for(int i=1;i<=li;i++) dp[i][0]=dp[i-1][0]+1;

	for(int i=1;i<=li;i++)
	{
		for(int j=1;j<=lo;j++)
		{
			//replacement
			int q1=dp[i-1][j-1];

			//deletion
			int q2=dp[i-1][j];

			//insertion
			int q3=dp[i][j-1];

			dp[i][j]=min(q1,min(q2,q3))+(input[i]!=output[j]);
		}
	}

	// for(int i=0;i<=li;i++)
	// {
	// 	for(int j=0;j<=lo;j++)
	// 	{
	// 		cout<<dp[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }

	return dp[li][lo];
}

int main(int argc, char const *argv[])
{
	string input,output;
	cin>>input>>output;
	int li=input.length();
	int lo=output.length();


	cout<<editDistBU(input,output)<<endl;


	for(int i=0;i<=li;i++)
	{
		for(int j=0;j<=lo;j++)
		{
			memo[i][j]=-1;
		}
	}
	count=0;
	cout<<editDistTD(input,output)<<"  "<<count<<endl;
	// for(int i=0;i<=li;i++)
	// {
	// 	for(int j=0;j<=lo;j++)
	// 	{
	// 		cout<<memo[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }

	count=0;
	cout<<editDist(input,output)<<"  "<<count<<endl;
	return 0;
}