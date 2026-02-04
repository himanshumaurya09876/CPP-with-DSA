#include <iostream>

using namespace std;

int main()
{
    int n[10],c=1;
    cout<<"Enter 10 numbers: "<<endl;
    for(int i=0;i<10;i++)
    {
        cin>>n[i];
    }
    int maxn=n[9];
    for(int i=8;i>=0;i--)
    {
        if(n[i]>maxn)
        {
            c++;
            maxn=n[i];
        }
    }
    cout<<"Final result is: "<<c<<endl;
    return 0;
}

///Enter 10 numbers:
///1 2 5 6 7 0 9 8 4 3
///Final result is: 4
