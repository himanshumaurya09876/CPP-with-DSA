#include <iostream>
#include <cmath>
#include <string>
#define ll long long int
using namespace std;

ll primeNo=7;

ll hashFun(string str,ll n)
{
	ll hashValue=0;
	for(int i=0;i<n;i++)
	{
		hashValue+=str[i]*pow(primeNo,i);
	}

	return hashValue;
}

ll rehashFun(string str,ll oldIdx,ll newIdx,ll oldHashValue,ll n)
{
	ll newHashValue=oldHashValue-str[oldIdx];
	newHashValue=newHashValue/primeNo;
	newHashValue+=str[newIdx]*pow(primeNo,n-1);
	return newHashValue;
}

int main()
{
	string str,pattern;
	cin>>str>>pattern;

	ll count=0,hashpat=0,hashstr=0;

	ll ls=str.length();
	ll lp=pattern.length();

	// this is a simple rolling hash function but it is not efficient ie it doesnot give unique hash values
	// // calculate hash value of pattern
	// for(ll i=0;i<lp;i++)
	// {
	// 	hashpat+=pattern[i];
	// }

	// // calculate hash value of first substring in str
	// for(ll i=0;i<lp;i++)
	// {
	// 	hashstr+=str[i];
	// }

	hashstr=hashFun(str,lp);
	hashpat=hashFun(pattern,lp);

	for(ll i=0;i<=ls-lp;i++)
	{
		if(i>0)
		{
			// hashstr=hashstr-str[i-1]+str[i+lp-1];//calculate hash value from previous in O(1)

			hashstr=rehashFun(str,i-1,i+lp-1,hashstr,lp);
		}

		if(hashpat==hashstr)
		{
			ll j;
			for(j=0;j<lp;j++)// double checking
			{
				if(str[j+i]!=pattern[j])
				{
					break;
				}
			}
			if(j==lp)
			{
				cout<<"Pattern found at "<<i<<endl;
				count++;
			}
		}
	}
	cout<<count;
	return 0;
}