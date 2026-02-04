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


// #include<iostream>
// using namespace std;
// int main() {
//     int t;
//     cin>>t;
//     while(t>0)
//     {
//         int n;
//         cin>>n;
//         long long int arr[100000]={0},csum=0;
//         int freqArr[100000]={0};
//         freqArr[0]=1;
//         for(int i=0;i<n;i++)
//         {
//             cin>>arr[i];
//             csum=csum+arr[i];
//             long long int mod=csum%n;
//             freqArr[mod]++;
//         }
//         int ans=0;
//         for(int i=0;i<n;i++)
//         {
//             long long int freq=freqArr[i];
//             ans+=(freq*(freq-1))/2;
//         }
//         cout<<ans<<endl;
//         t--;
//     }
// 	return 0;
// }


//for negative numbers
#include<iostream>
using namespace std;
int main() {
    long long int t;
    cin>>t;
    while(t>0)
    {
        long long int n;
        cin>>n;
        long long int arr[100001]={0},csum=0;
        long long int freqArr[100000]={0};
        freqArr[0]=1;
        for(long long int i=0;i<n;i++)
        {
            cin>>arr[i];
            csum=csum+arr[i];
            long long int mod=csum%n;
            if(mod<0)
            {
                mod=n+mod;
            }
            freqArr[mod]++;
        }
        long long int ans=0;
        for(long long int i=0;i<n;i++)
        {
            long long int freq=freqArr[i];
            ans+=(freq*(freq-1))/2;
        }
        cout<<ans<<endl;
        t--;
    }
    return 0;
}