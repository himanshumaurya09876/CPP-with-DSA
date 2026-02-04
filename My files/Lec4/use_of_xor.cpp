#include <iostream>

using namespace std;

int main()
{
    int n,res=0;
    cout<<"Enter nos."<<endl;
    cin>>n;
    while(n!=-1)
    {
        res=res^n;
        cin>>n;
    }
    cout<<"The number is: "<<res;
    return 0;
}
