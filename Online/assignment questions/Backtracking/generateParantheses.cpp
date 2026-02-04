// GENERATE PARENTHESES
// Given an integer 'n'. Print all the possible pairs of 'n' balanced parentheses.
// The output strings should be printed in the sorted order considering '(' has higher value than ')'.

// Input Format:
// Single line containing an integral value 'n'.

// Constraints:
// 1<=n<=11

// Output Format
// Print the balanced parentheses strings with every possible solution on new line.

// Sample Input
// 2
// Sample Output
// ()() 
// (()) 


#include<iostream>
using namespace std;

void printBalParentheses(int n,int open=0,int close=0,string output="")
{
    if(open==n && close==n)
    {
        cout<<output<<endl;
        return;
    }
    if(open>n || open<close)
    {
        return;
    }
    printBalParentheses(n,open,close+1,output+')');
    printBalParentheses(n,open+1,close,output+'(');
}

int main() {
    int n;
    cin>>n;
    printBalParentheses(n);
	return 0;
}