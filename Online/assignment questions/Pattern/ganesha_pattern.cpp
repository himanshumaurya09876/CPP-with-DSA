// 卐 GANESHA'S PATTERN
// Take as input N, an odd number (>=5) . Print the following pattern as given below for N = 7.

// *  ****
// *  *
// *  *
// *******
//    *  *
//    *  *
// ****  *
// Input Format:
// Enter value of N ( >=5 )

// Constraints:
// N >= 5

// Output Format
// Sample Input
// 7
// Sample Output
// *  ****
// *  *
// *  *
// *******
//    *  *
//    *  *
// ****  *


#include<iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if((i==1 && j>1 && j<=n/2) || (1<i && i<=n/2 && (j>n/2+1 || (j>1 && j<=n/2))) || (i>n/2+1 && i<n && (j<=n/2 || (j>n/2+1 && j<n))) || (i==n && j>n/2+1 && j<n))
                cout<<" ";
            else
                cout<<"*";
        }
        cout<<endl;
    }
	return 0;
}