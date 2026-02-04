#include <iostream>

using namespace std;

int main()
{
    int n;
    cout<<"Enter the number of rows: ";
    cin>>n;
    int row=1;
    int nst=1;
    int nsp=2*n-3;
    int m;
    while(row<=n)
    {
        int cst=1;
        int csp=1;
        m=1;
        while(cst<=nst)
        {
            cout<<m<<" ";
            m++;
            cst++;
        }
        while(csp<=nsp)
        {
            cout<<"  ";
            csp++;
        }
        m--;
        cst=1;
        if(row==n)
        {
            m--;
            cst=2;
        }
        while(cst<=nst)
        {
            cout<<m<<" ";
            m--;
            cst++;
        }
        cout<<endl;
        row++;
        nsp-=2;
        nst++;
    }
    return 0;
}
