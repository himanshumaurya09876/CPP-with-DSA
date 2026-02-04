// REVERSE A STACK USING RECURSION
// Reverse a Stack using Recursion.

// Input Format:
// First line contains an integer N (size of the stack). Next N lines follow each containing an integer to be stored in the stack where the last integer is at the top of the stack.

// Constraints:
// Output Format
// Output the values of the reversed stack with each value in following line.

// Sample Input
// 3
// 3
// 2
// 1
// Sample Output
// 3
// 2
// 1


#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int>& st,int data)
{
    if(st.empty())
    {
        st.push(data);
        return;
    }
    int topEle=st.top();
    st.pop();
    insertAtBottom(st,data);
    st.push(topEle);
}

void reverse(stack<int>& st)
{
    if(st.empty())
    {
        return;
    }
    int data=st.top();
    st.pop();
    reverse(st);
    insertAtBottom(st,data);
}

int main() {
    stack<int> st;
    int n,data;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>data;
        st.push(data);
    }
    reverse(st);
    while(!st.empty())
    {
        cout<<st.top()<<endl;
        st.pop();
    }
	return 0;
}