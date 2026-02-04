#include <iostream>

using namespace std;

int main()
{
    int numlist[10],n;
    cout <<"Enter 10 numbers: "<< endl;
    for(int i=0;i<10;i++)
    {
        cin>>numlist[i];
    }
    cout<<"Enter the number to be searched in the list: ";
    cin>>n;
    int i;
    for(i=0;i<10;i++)
    {
        if(numlist[i]==n)
        {
            cout<<n<<" successfully found at "<<i+1<<" index in the list."<<endl;
            break;
        }
    }
    if(i==10)
        cout<<n<<" does not found in the list."<<endl;
    return 0;
}
