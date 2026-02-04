#include<iostream>
using namespace std;

int dtoo(int n)
{
    int t=0,o=0;
    while(n>0)
    {
        t=10*t+n%8;
        n=n/8;
    }
    while(t>0)
    {
        o=o*10+t%10;
        t=t/10;
    }
    return o;
}

int main() {
    int n;
    cin>>n;
    cout<<dtoo(n);
	return 0;
}