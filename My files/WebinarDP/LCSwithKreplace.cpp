#include <iostream>
using namespace std;

//it is an example of 3D DP

int dp[200][200][200];
int calls;

int lcsK(string s1,string s2,int k,int i=0,int j=0)//using recursion only
{
	calls++;
	if(s1[i]=='\0' || s2[j]=='\0')
	{
		return 0;
	}

	int res=0;
	if(s1[i]==s2[j])
	{
		res=1+lcsK(s1,s2,k,i+1,j+1);
	}
	else
	{
		int q1=0,q2=0,q3=0;
		if(k>0)
		{
			q1=1+lcsK(s1,s2,k-1,i+1,j+1);
		}
		q2=lcsK(s1,s2,k,i+1,j);
		q3=lcsK(s1,s2,k,i,j+1);

		res=max(q1,max(q2,q3));
	}
	//cout<<i<<" "<<j<<" "<<res<<endl;
	return res;
}

int lcsKtopDownDP(string s1,string s2,int k,int i=0,int j=0)//using recursion only
{
	calls++;
	if(s1[i]=='\0' || s2[j]=='\0')
	{
		return 0;
	}

	if(dp[i][j][k]!=-1)
	{
		return dp[i][j][k];
	}

	int res=0;
	if(s1[i]==s2[j])
	{
		res=1+lcsKtopDownDP(s1,s2,k,i+1,j+1);
	}
	else
	{
		int q1=0,q2=0,q3=0;
		if(k>0)
		{
			q1=1+lcsKtopDownDP(s1,s2,k-1,i+1,j+1);
		}
		q2=lcsKtopDownDP(s1,s2,k,i+1,j);
		q3=lcsKtopDownDP(s1,s2,k,i,j+1);

		res=max(q1,max(q2,q3));
	}
	dp[i][j][k]=res;
	return res;
}

int main(int argc, char const *argv[])
{
	string s1,s2;
	int k;
	cin>>s1>>s2>>k;

	cout<<"**************Using recursion only***************"<<endl;
	calls=0;
	cout<<lcsK(s1,s2,k)<<endl;
	cout<<"calls="<<calls<<endl;

	cout<<"**************Using recursion with top down 3D dp***************"<<endl;
	for(int i=0;i<s1.length();i++)
	{
		for(int j=0;j<s2.length();j++)
		{
			for(int l=0;l<=k;l++)
			{
				dp[i][j][l]=-1;
			}
		}
	}
	calls=0;
	cout<<lcsKtopDownDP(s1,s2,k)<<endl;
	cout<<"calls="<<calls<<endl;
	// for(int i=0;i<s1.length();i++)
	// {
	// 	for(int j=0;j<s2.length();j++)
	// 	{
	// 		for(int l=0;l<=k;l++)
	// 		{
	// 			cout<<"("<<i<<", "<<j<<", "<<l<<") ->"<<dp[i][j][l]<<" || ";
	// 		}
	// 		cout<<endl<<"*************************************************"<<endl;
	// 	}
	// 	cout<<endl<<"______________________________________________________"<<endl<<endl;
	// }
	return 0;
}