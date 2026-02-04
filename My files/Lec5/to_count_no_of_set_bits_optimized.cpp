#include <bits/stdc++.h>

using namespace std;
void bin(unsigned int n)
{
    for(unsigned i=1<<(sizeof(int)*8-1);i>0;i>>=1)
        (n&i)?cout<<"1":cout<<"0";
}

int main()
{
    int n,b;
    cout<<"Enter a number: ";
    cin>>n;
    cout<<"In binary: ";
    bin(n);
    cout<<endl;
    cout<<"Enter how many its binary digits you want to rotate: ";
    cin>>b;
    int res=(n>>b)|(n<<(sizeof(int)*8-b));
    cout<<"After rotation we get: "<<res<<endl;
    cout<<"In binary: ";
    bin(res);
    cout<<endl;
    return 0;
}
