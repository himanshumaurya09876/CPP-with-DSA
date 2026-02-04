// UNIQUE NUMBERS - II
// We are given an array containg n numbers. All the numbers are present twice except for two numbers which are present only once. Find the unique numbers in linear time without using any extra space. ( Hint - Use Bitwise )

// Input Format:
// First line contains the number n. Second line contains n space separated number.

// Constraints:
// n < 10^5

// Output Format
// Output a single line containing the unique numbers separated by space

// Sample Input
// 4
// 3 1 2 1
// Sample Output
// 2 3

#include<iostream>
using namespace std;
int main() {
    int n,arr[100000],num[2];
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int k=0;
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
            num[k]=arr[i];
            k++;
            if(k==2)
            {
                break;
            }
        }
    }
    cout<<num[0]<<" "<<num[1];
	return 0;
}
