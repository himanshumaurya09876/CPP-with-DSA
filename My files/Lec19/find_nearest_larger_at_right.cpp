//find nearest larger at right
#include <iostream>
#include <stack>

using namespace std;

int main(int argc, char const *argv[])
{
	int arr[]={12,9,8,15,6,18,7};
	stack<int> st;
	int n=sizeof(arr)/sizeof(arr[0]);
	int *array=new int[n];
	// for(int i=0;i<n;i++)
	// {
	// 	if(st.empty())
	// 	{
	// 		st.push(arr[i]);
	// 	}
	// 	else
	// 	{
	// 		while(!st.empty() && st.top()<arr[i])
	// 		{
	// 			cout<<st.top()<<" "<<arr[i]<<endl;
	// 			st.pop();
	// 		}
	// 		st.push(arr[i]);
	// 	}
	// }
	// while(!st.empty())
	// {
	// 	cout<<st.top()<<" -1"<<endl;
	// 	st.pop();
	// }

	for(int i=0;i<n;i++)
	{
		if(st.empty())
		{
			st.push(i);
		}
		else
		{
			while(!st.empty() && arr[st.top()]<arr[i])
			{
				array[st.top()]=arr[i];
				st.pop();
			}
			st.push(i);
		}
	}
	while(!st.empty())
	{
		array[st.top()]=-1;
		st.pop();
	}

	for(int i=0;i<n;i++)
	{
		cout<<array[i]<<" ";
	}
	cout<<endl;
	return 0;
}