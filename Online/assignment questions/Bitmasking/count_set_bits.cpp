// COUNT SET BITS
// count number of 1s in binary representation of an integer

// Input Format:
// Input N = Number of Test Cases, followed by N numbers

// Constraints:
// Output Format
// Number of Set Bits in each number each in a new line

// Sample Input
// 3
// 5
// 4
// 15
// Sample Output
// 2
// 1
// 4

#include<iostream>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t>0)
    {
        int n,count=0;
        cin>>n;
        while(n!=0)
        {
            if(n&1)
            {
                count++;
            }
            n>>=1;
        }
        cout<<count<<endl;
        t--;
    }
	return 0;
}