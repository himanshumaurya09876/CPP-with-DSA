// STRINGS-REMOVE DUPLICATES
// Take as input S, a string. Write a function that removes all consecutive duplicates. Print the value returned.

// Input Format:
// String

// Constraints:
// A string of length between 1 to 1000

// Output Format
// String

// Sample Input
// aabccba
// Sample Output
// abcba


#include<iostream>
#include<string>
using namespace std;

string removedup(string input,string output="")
{
    if(input.length()==0)
    {
        return output;
    }
    if(input[0]!=input[1])
    {
        output+=input[0];
    }
    return removedup(input.substr(1),output);
}

int main() {
    string str;
    cin>>str;
    cout<<removedup(str);
	return 0;
}