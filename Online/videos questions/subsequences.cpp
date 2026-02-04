//subsequences

#include <iostream>
#include <string>

using namespace std;

void printSubsequences(string input,string output="")
{
	if(input[0]=='\0')
	{
		cout<<output<<endl;
		return;
	}	
	char ch=input[0];
	input=input.substr(1);
	printSubsequences(input,output+ch);
	printSubsequences(input,output);
}

int main()
{
	string str;
	cin>>str;
	printSubsequences(str);
	return 0;
}