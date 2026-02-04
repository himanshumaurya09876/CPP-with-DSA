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

void printSubsequences(string input,string output="")
{
	if(input[0]=='\0')
	{
		cout<<output<<" ";
		return;
	}	
	char ch=input[0];
	input=input.substr(1);
	printSubsequences(input,output);
    printSubsequences(input,output+ch);
}

int main()
{
	string str;
	cin>>str;
	printSubsequences(str);
    cout<<endl<<countSubsequences(str);
	return 0;
}