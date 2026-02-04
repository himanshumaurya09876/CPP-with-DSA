//dictionary order larger

//#include<iostream>
//#include<cstring>
//#include<cmath>

#include<bits/stdc++.h>
using namespace std;
int i=0;
void dictionary(string input,string permutations[1000],string output="")
{
	int l=input.length();
	if(l==0)
	{
		permutations[i]=output;
		//cout<<i<<endl<<permutations[i]<<endl;
		i++;
		return;
	}
	for(int j=0;j<l;j++)
	{
		char ch=input[j];
		dictionary(input.substr(0,j)+input.substr(j+1),permutations,output+ch);
	}
}

int main() {
	string str,permutations[1000];
	cin>>str;
	dictionary(str,permutations);
	sort(permutations,permutations+i-1);
	for(int j=0;j<i;j++)
	{
		cout<<permutations[i]<<endl;
	}
	return 0;
}
