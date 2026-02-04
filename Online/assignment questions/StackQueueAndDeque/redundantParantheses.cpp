// REDUNDANT PARENTHESES
// You are given an balanced expression. You have to find if it contains duplicate parentheses or not. A set of parentheses are duplicate if same subexpression is surrounded by multiple parenthesis.

// Input Format:
// First line contains integer t as number of test cases. Next t lines contains n expressions.

// Constraints:
// 1 < t < 100 1< expression < 100

// Output Format
// Print either given expression is Duplicate or Not Duplicates.

// Sample Input
// 2
// (((a+(b))+(c+d)))
// ((a+(b))+(c+d))
// Sample Output
// Duplicate
// Not Duplicates

#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isDuplicate(string str)
{
	stack<char> cont;
	int i=0;
	char flag='n';
	while(str[i]!='\0')
	{
		if(str[i]==')')
		{
			if(cont.top()=='(' && flag=='f')
			{
				return true;
			}
			while(cont.top()!='(')
			{
				cont.pop();
			}
			flag='f';
			cont.pop();
		}
		else
		{
			cont.push(str[i]);
			flag='n';
		}
		i++;
	}
	return false;
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t>0)
	{
		string str;
		cin>>str;
		if(isDuplicate(str))
		{
			cout<<"Duplicate"<<endl;
		}
		else
		{
			cout<<"Not Duplicates"<<endl;
		}
		t--;
	}
	return 0;
}