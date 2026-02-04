//stock span problem
#include <iostream>
#include <stack>
using namespace std;

void  findSol(int arr[],int sol[],int n)
{
	stack<int> st;
	st.push(0);
	sol[0]=0;
	for(int i=1;i<n;i++)
	{
		while(!st.empty() && arr[i]>arr[st.top()])
		{
			st.pop();
		}
		if(!st.empty())
			sol[i]=i-st.top();
		else
			sol[i]=0;
		st.push(i);
	}
}

int main(int argc, char const *argv[])
{
	int n,arr[100],sol[100];
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	findSol(arr,sol,n);
	for(int i=0;i<n;i++)
	{
		cout<<sol[i]<<" ";
	}
	return 0;
}