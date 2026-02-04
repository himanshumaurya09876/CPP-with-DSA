#include <iostream>
#include <math.h>

using namespace std;
void bin(unsigned int n)
{
    unsigned i;
    for(i=1<<31;i>0;i>>=1)
        (n&i)?cout<<"1":cout<<"0";
}

int main()
{
    int a,b;
    cout<<"Enter a and b:"<<endl;
    cin>>a>>b;
    cout<<"In binary your a is: ";
    bin(a);
    cout<<endl;
    for(int i=0;i<b;i++)
    {
        if(a&1)
        {
            a>>=1;
            a|=(int)(pow(2,sizeof(int)*8-2));
        }
        else
        {
            a>>=1;
        }
    }
    cout<<"Final result is: "<<a<<endl;
    cout<<"In binary final result is: ";
    bin(a);
    cout<<endl;
    return 0;
}
