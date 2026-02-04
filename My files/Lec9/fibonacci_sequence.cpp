#include <iostream>

using namespace std;

int fib(int n)
{
    if(n==0)
    {
        return 0;
    }
    else if(n==1)
    {
        return 1;
    }
    else
    {
        return (fib(n-1)+fib(n-2));
    }
}

int main()
{
    int n;
    cout<<"Enter the no.of terms of fibonacci sequence: ";
    cin>>n;
    cout<<fib(n);
    return 0;
}
