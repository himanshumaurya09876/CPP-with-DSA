// XOR PROFIT PROBLEM
// We are given two coins of value x and y. We have to find the maximum of value of a XOR b where x <= a <= b <= y.

// Input Format:
// We are given two integers x and y

// Constraints:
// l <= r <= 1000

// Output Format
// Print the maximum value of a XOR b

// Sample Input
// 5
// 6
// Sample Output
// 3

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x,y,a,b,max=INT_MIN;
    cin>>x>>y;
    for(a=x;a<=y;a++)
    {
        for(b=a;b<=y;b++)
        {
            int res=a^b;
            if(res>max)
            {
                max=res;
            }
        }
    }
    cout<<max;
    return 0;
}