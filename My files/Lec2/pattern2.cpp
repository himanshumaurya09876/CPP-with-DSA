#include <iostream>

using namespace std;

int main()
{
    int n;
    cout<<"Enter the number of rows: ";
    cin>>n;
    int row=1;
    int nst=1;
    int nsp=n-1;
    while(row<=n)
    {
        int csp=1;
        int cst=1;
        while(csp<=nsp)
        {
            cout<<" ";
            csp++;
        }
        while(cst<=nst)
        {
            cout<<"* ";
            cst++;
        }
        cout<<endl;
        nst++;
        nsp--;
        row++;
    }
    return 0;
}
