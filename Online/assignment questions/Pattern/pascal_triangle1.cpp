// PASCAL TRIANGLE 1
// Given an integer N, print Pascal Triangle upto N rows. 

// Input Format:
// Single integer N.

// Constraints:
// N <= 10

// Output Format
// Print pascal triangle.

// Sample Input
// 4
// Sample Output
//            1
//          1   1
//        1   2   1
//      1   3   3   1


#include<iostream>
using namespace std;
long int fact(int n)
{
    long int res=1;
    for(int i=1;i<=n;i++)
    {
        res=res*i;
    }
    return res;
}
int comb(int n,int r)
{
    return (fact(n)/(fact(r)*fact(n-r)));
}
 
int main() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n-i;j++)
        {
            cout<<" ";
        }
        for(int j=1;j<=i;j++)
        {
            cout<<comb(i-1,j-1)<<" ";
        }
        cout<<endl;
    }
	return 0;
}