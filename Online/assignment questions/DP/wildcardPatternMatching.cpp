// WILDCARD PATTERN MATCHING
// Given a text 'str' and a wildcard pattern 'pattern', The wildcard pattern can include the characters ‘?’ and ‘ * ’.
// ‘?’ – matches any single character
// ‘*’ – Matches any sequence of characters (including the empty sequence)
// Find out if the given text matches the pattern.

// Input Format:
// Every test file will consist of two strings. First string represents 'str'. Second string represents 'pattern'.

// Constraints:
// Size(str)*Size(pattern) < 100000000

// Output Format
// Print 1 if the string matches the pattern, else print 0.

// Sample Input
// aa a*a
// Sample Output
// 1


//******************************************************************************************************************************************************
// #include <iostream>
// #include <cstring>
// using namespace std;
// int memo[100][100];
// int count;
// bool isMatched(string str,string pattern,int i=0,int j=0)
// {
// 	count++;
// 	// cout<<str[i]<<"  "<<pattern[j]<<endl;
// 	if(str[i]=='\0' && pattern[j]=='\0')
// 	{
// 		return true;
// 	}
// 	else if(str[i]=='\0' || pattern[j]=='\0')
// 	{
// 		return false;
// 	}

// 	bool res=false;
// 	if(pattern[j]=='*')
// 	{
// 		int idx=-1;
// 		do
// 		{
// 			idx++;
// 			res=res || isMatched(str,pattern,i+idx,j+1);
// 			// cout<<res<<" "<<str[i+idx]<<endl;
// 			if(res)
// 			{
// 				return res;
// 			}
// 		}while(str[i+idx]!='\0');
// 	}
// 	else if(str[i]==pattern[j] || pattern[j]=='?')
// 	{
// 		res=isMatched(str,pattern,i+1,j+1);
// 	}

// 	return res;
// }

// bool isMatchedTD(string str,string pattern,int i,int j)
// {
// 	count++;
// 	if(str[i]=='\0' && pattern[j]=='\0')
// 	{
// 		return true;
// 	}
// 	else if(str[i]=='\0' || pattern[j]=='\0')
// 	{
// 		return false;
// 	}

// 	if(memo[i][j]!=-1)
// 	{
// 		return memo[i][j];
// 	}

// 	bool res=false;
// 	if(pattern[j]=='*')
// 	{
// 		int idx=-1;
// 		do
// 		{
// 			idx++;
// 			res=res || isMatchedTD(str,pattern,i+idx,j+1);
// 			if(res)
// 			{
// 				return res;
// 			}
// 		}while(str[i+idx]!='\0');
// 	}
// 	else if(str[i]==pattern[j] || pattern[j]=='?')
// 	{
// 		res=isMatchedTD(str,pattern,i+1,j+1);
// 	}
// 	memo[i][j]=res;
// 	// cout<<res<<" "<<i<<" "<<j<<endl;
// 	return res;
// }

// int main(int argc, char const *argv[])
// {
// 	string str,pattern;
// 	cin>>str>>pattern;


// 	count=0;
// 	cout<<isMatched(str,pattern)<<" "<<count<<endl;



// 	int n=str.length();
// 	int m=pattern.length();
// 	memset(memo,-1,sizeof(memo));
// 	count=0;
// 	cout<<isMatchedTD(str,pattern,0,0)<<" "<<count<<endl;

// 	// for(int i=0;i<n;i++)
// 	// {
// 	// 	for(int j=0;j<m;j++)
// 	// 	{
// 	// 		cout<<memo[i][j]<<" ";
// 	// 	}
// 	// 	cout<<endl;
// 	// }


// 	return 0;
// }



//******************************************************************************************************************************************************
// #include <iostream>
// #include <cstring>
// using namespace std;
// bool isMatchedBU(string str,string pattern)
// {
// 	int sl=str.length();
// 	int pl=pattern.length();
// 	bool **dp=new bool*[pl+1];
// 	for(int i=0;i<=pl;i++)
// 	{
// 		dp[i]=new bool[sl+1];
// 	}

// 	for(int i=0;i<=pl;i++)
// 	{
// 		dp[i][0]=false;
// 	}

// 	for(int i=0;i<=sl;i++)
// 	{
// 		dp[0][i]=false;
// 	}

// 	dp[0][0]=true;

// 	for(int i=1;i<=pl;i++)
// 	{
// 		for(int j=1;j<=sl;j++)
// 		{	
// 			if((str[j-1]==pattern[i-1] || pattern[i-1]=='?') && dp[i-1][j-1])
// 			{
// 				dp[i][j]=true;
// 			}
// 			else if((pattern[i-1]=='*') && (dp[i-1][j] || dp[i-1][j-1]))
// 			{
// 				while(j<=sl)
// 				{
// 					dp[i][j]=true;
// 					j++;
// 				}
// 			}
// 			else
// 			{
// 				dp[i][j]=false;
// 			}
// 		}
// 	}


// 	cout<<"    ";
// 	for(int j=0;j<=sl;j++)
// 	{
// 		cout<<str[j]<<" ";
// 	}
// 	cout<<endl;
// 	for(int i=0;i<=pl;i++)
// 	{
// 		if(i>0)
// 		{
// 			cout<<pattern[i-1]<<" ";
// 		}
// 		else
// 		{
// 			cout<<"  ";
// 		}
// 		for(int j=0;j<=sl;j++)
// 		{
// 			cout<<dp[i][j]<<" ";
// 		}
// 		cout<<endl;
// 	}

// 	return dp[pl][sl];
// }

// int main(int argc, char const *argv[])
// {
// 	string str,pattern;
// 	cin>>str>>pattern;
// 	cout<<isMatchedBU(str,pattern)<<endl;
// 	return 0;
// }
//******************************************************************************************************************************************************



#include <iostream>
#include <cstring>
using namespace std;
bool isMatchedBU(string str,string pattern)
{
	int sl=str.length();
	int pl=pattern.length();
	bool **dp=new bool*[pl+1];
	for(int i=0;i<=pl;i++)
	{
		dp[i]=new bool[sl+1];
	}

	for(int i=0;i<=pl;i++)
	{
		dp[i][0]=false;
	}

	for(int i=0;i<=sl;i++)
	{
		dp[0][i]=false;
	}

	dp[0][0]=true;

	for(int i=1;i<=pl && pattern[i-1]=='*';i++)
	{
		dp[i][0]=true;
	}

	for(int i=1;i<=pl;i++)
	{
		for(int j=1;j<=sl;j++)
		{	
			if((str[j-1]==pattern[i-1] || pattern[i-1]=='?') && dp[i-1][j-1])
			{
				dp[i][j]=true;
			}
			else if((pattern[i-1]=='*') && (dp[i-1][j] || dp[i-1][j-1]))
			{
				while(j<=sl)
				{
					dp[i][j]=true;
					j++;
				}
			}
			else
			{
				dp[i][j]=false;
			}
		}
	}


	// cout<<"    ";
	// for(int j=0;j<=sl;j++)
	// {
	// 	cout<<str[j]<<" ";
	// }
	// cout<<endl;
	// for(int i=0;i<=pl;i++)
	// {
	// 	if(i>0)
	// 	{
	// 		cout<<pattern[i-1]<<" ";
	// 	}
	// 	else
	// 	{
	// 		cout<<"  ";
	// 	}
	// 	for(int j=0;j<=sl;j++)
	// 	{
	// 		cout<<dp[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }

	return dp[pl][sl];
}

int main(int argc, char const *argv[])
{
	string str,pattern;
	cin>>str>>pattern;
	cout<<isMatchedBU(str,pattern)<<endl;
	return 0;
}