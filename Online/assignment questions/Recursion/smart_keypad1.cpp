//smart keypad 1

#include <iostream>
#include <string>

using namespace std;

string table[] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };

void printKeys(string input,string output="")
{
	if(input[0]=='\0')
	{
		cout<<output<<endl;
		return;
	}
	int n=input[0]-'0';
	int l=table[n].length();
	for(int i=0;i<l;i++)
	{
		printKeys(input.substr(1),output+table[n][i]);
	}
}

int main()
{
	string str;
	cin>>str;
	printKeys(str);
	return 0;
}