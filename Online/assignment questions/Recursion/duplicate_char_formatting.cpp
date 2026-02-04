// RECURSION-DUPLICATE CHARACTER FORMATTING
// Take as input str, a string. Write a recursive function which returns a new string in which all duplicate consecutive characters are separated by a ‘ * ’. E.g. for “hello” return “hel*lo”. Print the value returned

// Input Format:
// Enter a String

// Constraints:
// None

// Output Format
// Display the resulting string (i.e after inserting (*) b/w all the duplicate characters)

// Sample Input
// hello
// Sample Output
// hel*lo

#include<iostream>
#include<string>
using namespace std;

string manipulateString(string input,string output="")
{
    if(input.length()==0)
    {
        return output;
    }
    output+=input[0];
    if(input[0]==input[1])
    {
        output+='*';
    }
    return manipulateString(input.substr(1),output);
}

int main() {
    string str;
    cin>>str;
    cout<<manipulateString(str);
	return 0;
}