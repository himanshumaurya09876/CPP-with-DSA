// DIVISIBLE SUBARRAYS
// You are given N elements, a1,a2,a3….aN. Find the number of good sub-arrays.
// A good sub-array is a sub-array [ai,ai+1,ai+2….aj] such that (ai+ai+1+ai+2+….+aj) is divisible by N.

// Input Format:
// The first line contains the number of test cases T. First line of each test case contains an integer N denoting the number of elements. Second line of each test case contains N integers, a1, a2, a3….aN, where ai denotes the ith element of the array.

// Constraints:
// 1<=T<=10 1<=N<=10^5 |ai|<=10^9

// Output Format
// Output a single integer denoting the number of good sub-arrays.

// Sample Input
// 2
// 5
// 1 1 1 1 1
// 5
// 5 5 5 5 5
// Sample Output
// 1
// 15


#include<iostream>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t>0)
    {
        int n,arr[100001]={0};
        long long int csum[100001]={0};
        int count=0;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        for(int i=0;i<n;i++)
        {
            csum[i+1]=arr[i]+csum[i];
        }
        // for(int i=0;i<=n;i++)
        // {
        //     cout<<csum[i]<<" ";
        // }
        // cout<<endl;
        for(int i=0;i<=n;i++)
        {
            for (int j=i+1;j<=n;j++)
            {
                if((csum[j]-csum[i])%n == 0)
                {
                    count++;
                }
            }
        }
        cout<<count<<endl;
        t--;
    }
    return 0;
}