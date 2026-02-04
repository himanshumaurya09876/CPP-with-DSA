// BALANCED PARENTHESIS
// You are given a string of '(' and ')'. You have to steck whether the sequence of parenthesis is balanced or not. For example, "(())", "(())()" are balanced and "())(", "(()))" are not.

// Input Format:
// A string of '(' , ')' , '{' , '}' and '[' , ']' .

// Constraints:
// 1<=|S|<=10^5

// Output Format
// Print "Yes" if the parenthesis are balanced and "No" if not balanced.

// Sample Input
// (())
// Sample Output
// Yes


#include<iostream>
#include<stack>
using namespace std;

bool isBalanced(string str)
{
	stack<char> ch;
	int i=0;
	while(str[i]!='\0')
	{
		switch(str[i])
		{
			case '(':
			case '{':
			case '[':ch.push(str[i]);
					break;
			case ')':if(ch.empty() || ch.top()!='(')
					{
						return false;
					} 
					else
					{
						ch.pop();
					}
					break;
			case '}':if(ch.empty() || ch.top()!='{')
					{
						return false;
					} 
					else
					{
						ch.pop();
					}
					break;
			case ']':if(ch.empty() || ch.top()!='[')
					{
						return false;
					} 
					else
					{
						ch.pop();
					}
					break;
		}
		i++;
	}
	if(ch.empty())
	{
		return true;
	}
	return false;
}

int main() {
	string str;
	cin>>str;
	if(isBalanced(str))
	{
		cout<<"Yes"<<endl;
	}
	else
	{
		cout<<"No"<<endl;
	}
	return 0;
}