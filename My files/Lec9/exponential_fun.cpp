#include <iostream>

using namespace std;

long long int expo(int n,int p)
{
    if(p==0)
    {
        return 1;
    }
    else
    {
        return (n*expo(n,p-1));
    }
}

int main()
{
    int n,p;
    cout << "Enter the number: ";
    cin>>n;
    cout<<"Enter power: ";
    cin>>p;
    cout<<n<<"^"<<p<<"="<<expo(n,p);
    return 0;
}
