// DEEPAK AND PRIMES
// Deepak is learning Sieve of Eratosthenes, He is stuck somewhere. Help him printing prime numbers.

// Input Format:
// Single line containing integral value n.

// Constraints:
// 1<=n<=5000000

// Output Format
// Integral value denoting nth prime number.

// Sample Input
// 1
// Sample Output
// 2


#include<bits/stdc++.h>
using namespace std;
int main() {
    bool arr[100000001]={0};
    long long int prime[5000001]={0};
    long long int n,s=100000001;
    arr[2]=1;
    for(long long int i=3;i<s;i+=2)
    {
        arr[i]=1;
    }
    for(long long int i=3;i<s;i+=2)
    {
        for(long long int j=i*i;j<s;j+=2*i)
        {
            arr[j]=0;
        }
    }
    long long int j=1;
    cin>>n;
    for(long long int i=0;i<s;i++)
    {
        if(arr[i]==1)
        {
            prime[j]=i;
            j++;
        }
        if(j>n)
        {
            break;
        }
    }
    cout<<prime[n]<<endl;
    return 0;
}