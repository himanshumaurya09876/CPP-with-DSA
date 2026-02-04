// RECURSION-CONVERT STRING TO INTEGER
// Take as input str, a number in form of a string. Write a recursive function to convert the number in string form to number in integer form. E.g. for “1234” return 1234. Print the value returned.

// Input Format:
// Enter a number in form of a String

// Constraints:
// None

// Output Format
// Print the number after converting it into integer

// Sample Input
// 1234
// Sample Output
// 1234

#include<iostream>
#include<string>
using namespace std;

int str_to_int(string str,int num=0)
{
    int l=str.length();
    if(l==0)
    {
        return num;
    }
    num=num*10+(str[0]-'0');
    return str_to_int(str.substr(1),num);
}

int main() {
    string str;
    cin>>str;
    int num=str_to_int(str);
    cout<<num;
	return 0;
}