#include <iostream>

using namespace std;

int combinations(int n)
{
    if(n<=2)
        return n;
    return (combinations(n-1)+(n-1)*combinations(n-2));
}

int main()
{
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    cout<<"Final combinations are: "<<combinations(n)<<endl;
    return 0;
}
