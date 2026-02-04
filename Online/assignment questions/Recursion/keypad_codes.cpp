//keypad codes

#include<iostream>
using namespace std;
string keypad[] = {"","abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wx","yz"};

void printWords(string input,string output="")
{
	if(input[0]=='\0')
	{
		cout<<output<<" ";
		return;
	}
	int n=input[0]-'0';
	int l=keypad[n].length();
	for(int i=0;i<l;i++)
	{
		printWords(input.substr(1),output+keypad[n][i]);
	}
}

int countWords(string input)
{
	if(input[0]=='\0')
	{
		return 1;
	}
	int n=input[0]-'0';
	int l=keypad[n].length();
	return l*countWords(input.substr(1));
}

int main() {
	string str;
	cin>>str;
	printWords(str);
	cout<<endl<<countWords(str)<<endl;
	return 0;
}