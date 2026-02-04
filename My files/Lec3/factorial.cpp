#include <iostream>

using namespace std;

int main()
{
    int n;
    long long int fact=1;
    cout << "Enter a number: ";
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        fact=fact*i;
    }
    cout<<n<<"! = "<<fact;
    return 0;
}
