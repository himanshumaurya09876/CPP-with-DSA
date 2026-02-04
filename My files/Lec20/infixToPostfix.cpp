#include <iostream>
#include <string>
#include <stack>
using namespace std;

int checkPrec(char ch)
{
	switch(ch)
	{
		case '^':return 3;
		case '*':
		case '/':
		case '%':return 2;
		case '+':
		case '-':return 1;
		case '(':
		case ')':return 0;
		default:return -1;
	}
}

string infixToPostfix(string input,string output="")
{
	stack<char> st;
	st.push('(');
	int i=0;
	while(input[i]!='\0')
	{
		int prec=checkPrec(input[i]);
		if(prec==-1)
		{
			output+=input[i];
		}
		else if(prec==0)
		{
			if(input[i]=='(')
			{
				st.push(input[i]);
			}
			else
			{
				while(st.top()!='(')
				{
					output+=st.top();
					st.pop();
				}
				st.pop();
			}
		}
		else
		{
			if(checkPrec(st.top())<=prec)
			{
				st.push(input[i]);
			}
			else
			{
				while(checkPrec(st.top())>prec)
				{
					output+=st.top();
					st.pop();
				}
				st.push(input[i]);
			}
		}
		i++;
	}
	while(st.top()!='(')
	{
		output+=st.top();
		st.pop();
	}
	st.pop();
	return output;
}

int main(int argc, char const *argv[])
{
	string input,output="";
	cin>>input;
	output=infixToPostfix(input);
	cout<<output<<endl;
	return 0;
}