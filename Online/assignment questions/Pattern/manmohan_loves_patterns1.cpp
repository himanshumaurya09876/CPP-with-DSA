// MANMOHAN LOVES PATTERNS - I
// Given N, help Manmohan to print pattern upto N lines. For eg For N=6 , following pattern will be printed.

// 1
// 11
// 111
// 1001
// 11111
// 100001

// Input Format:
// Single number N.

// Constraints:
// N<=1000

// Output Format
// Pattern corresponding to N.

// Sample Input
// 6
// Sample Output
// 1 
// 11
// 111 
// 1001 
// 11111
// 100001


#include<iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int row=n;
    for(int crow=1;crow<=row;crow++)
    {
        int col=crow;
        for(int ccol=1;ccol<=col;ccol++)
        {
            if(crow%2==0)
            {
                if(ccol==1 || ccol==col)
                    cout<<"1";
                else
                    cout<<"0";
            }
            else
                cout<<"1";
        }
        cout<<endl;
    }
	return 0;
}