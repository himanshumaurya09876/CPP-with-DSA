#include <iostream>

using namespace std;

long int fact(int num)
{
    long int res=1;
    while(num>0)
    {
        res=res*num;
        num--;
    }
    return res;
}

long int comb(int n,int r)
{
    return(fact(n)/(fact(r)*fact(n-r)));
}

int main()
{
    int n,r;
    cout<<"Enter n and r for combinations: ";
    cin>>n>>r;
    cout<<"Final answer is: "<<comb(n,r)<<endl;
    return 0;
}
