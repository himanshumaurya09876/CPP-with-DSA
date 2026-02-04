//subsequences count

#include <iostream>
#include <string>

using namespace std;

int countSubsequences(string input,string output="")
{
	if(input[0]=='\0')
	{
		return 1;
	}	
	char ch=input[0];
	input=input.substr(1);
	int res=countSubsequences(input,output+ch)+countSubsequences(input,output);
	return res;
}

int main()
{
	string str;
	cin>>str;
	cout<<countSubsequences(str);
	return 0;
}