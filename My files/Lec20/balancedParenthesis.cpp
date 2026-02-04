#include <iostream>
#include <stack>
using namespace std;

bool isBalanced(string str)
{
	stack<char> ch;
	int i=0;
	while(str[i]!='\0')
	{
		if(str[i]=='(')
		{
			ch.push(str[i]);
		}
		else
		{
			if(ch.empty() || ch.top()!='(')
			{
				return false;
			}
			else
			{
				ch.pop();
			}
		}
		i++;
	}
	if(ch.empty())
	{
		return true;
	}
	return false;
}

int main(int argc, char const *argv[])
{
	string str;
	cin>>str;
	cout<<isBalanced(str)<<endl;
	return 0;
}