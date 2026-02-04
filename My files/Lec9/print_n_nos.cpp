#include <iostream>

using namespace std;

void display1(int n)
{
    cout<<n<<endl;
    if(n==0)
    {
        return;
    }
    else
    {
        display1(n-1);
    }
}

/*void display2(int n,int i=0)
{
    cout<<i<<endl;
    if(i==n)
    {
        return;
    }
    else
    {
        display2(n,i+1);
    }
}*/

void display2(int n)
{
    if(n<0)
    {
        return;
    }
    else
    {
        display2(n-1);
    }
    cout<<n<<endl;
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin>>n;
    cout<<"Numbers are"<<endl;
    display1(n);
    cout<<"Enter again: ";
    cin>>n;
    cout<<"Numbers are"<<endl;
    display2(n);
    return 0;
}
