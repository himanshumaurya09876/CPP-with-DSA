//prime visits optimized
//Sieve of Eratosthenes
//prime sieve
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll n;
    bool primeArr[1000];
    ll s=1000;
    fill(primeArr,primeArr+s,0);
    primeArr[2]=1;
    // //one bruteforce method is checking all numbers one by one, whether it is prime or not

    // //secong method, below method is just a little optimized
    // for(ll i=2;i<s;i++)//initially assuming all numbers to be prime
    // {
    //     arr[i]=1;
    // }
    // for(ll i=2;i<s;i++)
    // {
    //     if(arr[i]!=0)
    //     {
    //         for(ll j=2*i;j<s;j+=i)
    //         {
    //             arr[i]=0;
    //         }
    //     }
    // }
    // //prll all prime numbers
    // for(ll i=0;i<s;i++)
    // {
    //     if(arr[i]==1)
    //     {
    //         cout<<arr[i]<<" ";
    //     }
    // }
    // cout<<endl;
    //list of optimizations applied on above second method to make it most efficient
    for(ll i=3;i<s;i+=2)//1st optimization (i+=2)->because all even numbers are non prime so we take only odd numbers
    {
    	primeArr[i]=1;
    }
    for(ll i=3;i<s;i+=2)//2nd optimization (i+=2)->check multiples of odd only because multiples of even are also even so already zero
    {
    	if(primeArr[i])
        {
            for(ll j=i*i;j<s;j+=2*i)//3rd optimization (j=i*i)->because all multiples of i below i*i will be already made as 0 due to its lower i's
            //for eg 5*3=15 will already have 0 due to 3 so no need to make it 0 due to 5 just start looking from 5*5=25
            //4th optimization (j+=2*i)->because j will be odd (odd*odd=odd) and odd+odd=even which again can not be prime so we are 
            //adding only even to odd(j) to have only odd result ie (odd+even=odd) so here j+=2*i
            {
                primeArr[j]=0;
            }
        }
    }
    // //prll all prime numbers
    // for(ll i=0;i<s;i++)
    // {
    //     if(primeArr[i])
    //     {
    //         cout<<i<<" ";
    //     }
    // }
    // cout<<endl;
    cin>>n;
    while(n>0)
    {
        ll a,b,count=0;
        cin>>a>>b;
        for(ll i=a;i<=b;i++)
        {
        	if(primeArr[i]==1)
        	{
        		count++;
        	}
        }
        cout<<count<<endl;
        n--;
    }
	return 0;
}
