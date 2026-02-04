//all permutations which are smaller than the given string in dictionary order
#include<iostream>
#include<string>
using namespace std;

void dictionary(string str,string input,string output="",bool flag = false)
{
	int l=input.length();
	if(l==0)
	{
		if(output!=str)
			cout<<output<<endl;
		return;
	}
	for(int j=0;j<l;j++)
	{
		char ch=input[j];
		if(flag || ch<=input[0])
		{
			dictionary(str,input.substr(0,j)+input.substr(j+1),output+ch, flag);
		}
	}
}

int main() {
	string str;
	cin>>str;
	dictionary(str,str);
	return 0;
}