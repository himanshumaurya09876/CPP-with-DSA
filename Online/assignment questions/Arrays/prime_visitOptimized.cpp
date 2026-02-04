//prime visits optimized
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n;
    bool primeArr[1000001]={0};
    long long int s=1000001;
    primeArr[2]=1;
    for(long long int i=3;i<s;i+=2)//1st optimization (i+=2)->because all even numbers are non prime so we take only odd numbers
    {
    	primeArr[i]=1;
    }
    for(long long int i=3;i<s;i++)
    {
    	for(long long int j=i*i;j<s;j+=2*i)//2nd optimization (j=i*i)->because all multiples of i below i*i will be already made as 0 due to its lower i's
    	//for eg 5*3=15 will already have 0 due to 3 so no need to make it 0 due to 5 just start looking from 5*5=25
    	//3rd optimization (j+=2*i)->because j will be odd (odd*odd=odd) and odd+odd=even which again can not be prime so we are 
    	//adding only even to odd(j) to have only odd result ie (odd+even=odd) so here j+=2*i
    	{
    		//cout<<i<<" "<<j<<endl;
            primeArr[j]=0;
    	}
    }
    cin>>n;
    while(n>0)
    {
        int a,b,count=0;
        cin>>a>>b;
        for(long long int i=a;i<=b;i++)
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
