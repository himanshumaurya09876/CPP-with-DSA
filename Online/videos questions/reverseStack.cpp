//(1) reverse a stack using 2 extra stacks
//(2) reverse a stack using 1 extra stack
//(3) reverse a stack using recursion and no extra stack
#include <iostream>
#include <stack>
using namespace std;

void reverseStack1(stack<int>& st)//using 2 extra stacks
{
	stack<int> st1,st2;
	while(!st.empty())
	{
		st1.push(st.top());
		st.pop();
	}
	while(!st1.empty())
	{
		st2.push(st1.top());
		st1.pop();
	}
	while(!st2.empty())
	{
		st.push(st2.top());
		st2.pop();
	}
}

void reverseStack2(stack<int>& st)
{
	stack<int> st1;
	int s=st.size();
	for(int i=0;i<s;i++)
	{
		int topEle=st.top();
		st.pop();
		for(int j=0;j<s-i-1;j++)
		{
			st1.push(st.top());
			st.pop();
		}
		st.push(topEle);
		for(int j=0;j<s-i-1;j++)
		{
			st.push(st1.top());
			st1.pop();
		}
	}
}

void insertAtBottom(stack<int>& st,int ele)
{
	if(st.empty())
	{
		st.push(ele);
		return;
	}
	int topEle=st.top();
	st.pop();
	insertAtBottom(st,ele);
	st.push(topEle);
}

void reverseStack3(stack<int>& st)
{
	if(st.empty())
	{
		return;
	}
	int topEle=st.top();
	st.pop();
	reverseStack3(st);
	insertAtBottom(st,topEle);
}

int main(int argc, char const *argv[])
{
	stack<int> st,st1;
	for(int i=10;i>0;i--)
	{
		st.push(i);
	}
	st1=st;
	cout<<"Original stack is:"<<endl;
	while(!st1.empty())
	{
		cout<<st1.top()<<endl;
		st1.pop();
	}
	//reverseStack1(st);
	//reverseStack2(st);
	reverseStack3(st);
	cout<<"After reversing stack becomes:"<<endl;
	while(!st.empty())
	{
		cout<<st.top()<<endl;
		st.pop();
	}
	return 0;
}