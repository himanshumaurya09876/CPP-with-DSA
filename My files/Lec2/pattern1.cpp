#include <iostream>

using namespace std;

int main()
{
    int n,m;
    cout<<"Enter the number of rows: ";
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        m=1;
        for(int j=1;j<=2*i-1;j++)
        {
            cout<<m<<" ";
            if(j<i)
                m++;
            else
                m--;
        }
        cout<<endl;
    }
    return 0;
}
