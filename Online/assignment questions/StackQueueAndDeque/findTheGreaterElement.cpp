// FIND THE GREATER ELEMENT
// We are given a circular array, print the next greater number for every element. If it is not found print -1 for that number. To find the next greater number for element Ai , start from index i + 1 and go uptil the last index after which we start looking for the greater number from the starting index of the array since array is circular.

// Input Format:
// First line contains the length of the array n. Second line contains the n space separated integers.

// Constraints:s
// Output Format
// Print n space separated integers each representing the next greater element.

// Sample Input
// 3
// 1 2 3
// Sample Output
// 2 3 -1

#include <iostream>
#include <stack>
using namespace std;

//bruteforce approach
void printNextGreater(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		int k=(i+1)%n;
		int j;
		if(arr[k]>arr[i])
		{
			cout<<arr[k]<<" ";
			continue;
		}
		for(j=(k+1)%n;j!=k;j=(j+1)%n)
		{
			if(arr[j]>arr[i])
			{
				cout<<arr[j]<<" ";
				break;
			}
		}
		if(j==k)
		{
			cout<<-1<<" ";
		}
	}
}

//using stack
void printNextGreater1(int arr[],int n)
{
	stack<int> st;
	int *ans=new int[n];
	fill(ans,ans+n,-1);
	for(int i=0;i<n;i++)
	{
		while(!st.empty() && arr[st.top()]<arr[i])
		{
			ans[st.top()]=arr[i];
			st.pop();
		}
		st.push(i);
	}

	int j=st.top();
	for(int i=0;i<j;i++)
	{
		while(!st.empty() && arr[st.top()]<arr[i])
		{
			ans[st.top()]=arr[i];
			st.pop();
		}
		st.push(i);
	}

	for(int i=0;i<n;i++)
	{
		cout<<ans[i]<<" ";
	}
	cout<<endl;
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int *arr=new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	printNextGreater1(arr,n);
	return 0;
}