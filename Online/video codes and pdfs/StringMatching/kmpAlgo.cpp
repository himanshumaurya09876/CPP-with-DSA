#include <iostream>
#include <cmath>
#include <string>
#define ll long long int
using namespace std;

void buildResetTable(string str,int reset[],int n)
{
	int i=0,j=-1;
	reset[0]=-1;
	while(i<n)
	{
		while(j>=0 and str[i]!=str[j])
		{
			j=reset[j];
		}
		i++;
		j++;
		reset[i]=j;
	}
}

int main()
{
	string str,pattern;
	cin>>str>>pattern;

	ll count=0;

	ll ls=str.length();
	ll lp=pattern.length();

	//reset table is build here
	int *reset=new int[lp];
	buildResetTable(pattern,reset,lp);
	cout<<"Reset table is -> ";
	for(int i=0;i<lp;i++)
	{
		cout<<reset[i]<<" ";
	}
	cout<<endl;

	int j=0;
	for(int i=0;i<ls;i++)
	{
		while(j>=0 and str[i]!=pattern[j])
		{
			j=reset[j];
		}
		j++;

		// cout<<"("<<i<<", "<<j<<"), ";

		if(j==lp)
		{
			cout<<"Pattern found at "<<i-lp+1<<endl;
			count++;
			j=0;
		}
	}
	cout<<count;
	return 0;
}