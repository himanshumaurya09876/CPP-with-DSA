#include <iostream>

using namespace std;

int main()
{
    int n;
    cout<<"Enter the number of rows: ";
    cin>>n;
    int row=1;
    int nst=1;
    int m=1;
    int nsp=n-1;
    while(row<=n)
    {
        int csp=1;
        int cst=1;
        while(csp<=nsp)
        {
            cout<<"  ";
            csp++;
        }
        m=1;
        while(cst<=2*nst-1)
        {
            cout<<m<<" ";
            if(cst<nst)
            {
                m++;
            }
            else
            {
                m--;
            }
            cst++;
        }
        cout<<endl;
        nsp--;
        nst++;
        row++;
    }
    return 0;
}
