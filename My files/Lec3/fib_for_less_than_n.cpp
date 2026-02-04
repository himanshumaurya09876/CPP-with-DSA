#include <iostream>

using namespace std;

void fib(int n)
{
    int a=0;
    int b=1;
    int res=a+b;
    cout<<"Fibonacci sequence till "<<n<<" is: ";
    while(a<=n)
    {
        cout<<a<<" ";
        a=b;
        b=res;
        res=a+b;
    }
}

int main()
{
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    fib(n);
    return 0;
}
