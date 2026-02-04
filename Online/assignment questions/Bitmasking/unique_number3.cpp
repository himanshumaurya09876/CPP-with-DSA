// First line contains the number n. Second line contains n space separated number.

// Constraints:
// N < 10^5

// Output Format
// Output a single line containing the unique number

// Sample Input
// 7
// 1 1 1 2 2 2 3
// Sample Output
// 3

#include<iostream>
using namespace std;
int main() {
    int n,arr[100000],num;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<n;i++)
    {
        char flag='y';
        for(int j=0;j<n;j++)
        {
            if(!(arr[i]^arr[j]) && i!=j)
            {
                flag='n';
                break;
            }
        }
        if(flag=='y')
        {
            num=arr[i];
            break;
        }
    }
    cout<<num;
	return 0;
}
