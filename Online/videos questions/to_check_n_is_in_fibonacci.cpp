#include <iostream>

using namespace std;

int main()
{
    int a=0,b=1,c=a+b,n;
    cout<<"Enter the number to be checked: ";
    cin>>n;
    for(int i=0;a<=n;i++)
    {
        if(a==n)
        {
            cout<<n<<" is "<<i<<"th member of fibonacci sequence"<<endl;
            break;
        }
        a=b;
        b=c;
        c=a+b;
    }
    if(a>n)
        cout<<n<<" is not a member of fibonacci sequence"<<endl;
    return 0;
}
