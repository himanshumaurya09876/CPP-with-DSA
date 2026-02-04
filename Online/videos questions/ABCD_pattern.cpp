#include <iostream>

using namespace std;

int main()
{
    int n;
    cout<<"Enter the number of rows: ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        char ch='A';
        for(int j=0;j<n-i;j++)
        {
            cout<<ch;
            ch=ch+1;
        }
        ch=ch-1;
        for(int j=0;j<n-i;j++)
        {
            cout<<ch;
            ch=ch-1;
        }
        cout<<endl;
    }
    return 0;
}
