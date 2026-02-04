// FIBONACCI PATTERN (PATTERN 4)
// Take N (number of rows), print the following pattern (for N = 4)
// 0
// 1 1
// 2 3 5
// 8 13 21 34

// Input Format:
// Constraints:
// 0 < N < 100

// Output Format
// Sample Input
// 4
// Sample Output
// 0 
// 1    1 
// 2    3     5 
// 8   13    21    34


#include<iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int a=0,b=1,res=a+b;
    for(int row=1;row<=n;row++)
    {
        for(int column=1;column<=row;column++)
        {
            cout<<a<<" ";
            a=b;
            b=res;
            res=a+b;
        }
        cout<<endl;
    }
	return 0;
}