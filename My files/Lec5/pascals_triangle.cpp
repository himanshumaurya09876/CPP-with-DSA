#include <iostream>

using namespace std;

long int fact(int n)
{
    int res=1;
    while(n>=1)
    {
        res=res*n;
        n--;
    }
    return res;
}

int comb(int n,int r)
{
    return (fact(n)/(fact(r)*fact(n-r)));
}

int main()
{
    int n;
    cout<<"Enter the number of rows: ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            cout<<" ";
        }
        for(int j=0;j<=i;j++)
        {
            cout<<comb(i,j)<<" ";
        }
        cout<<endl;
    }
    return 0;
}
