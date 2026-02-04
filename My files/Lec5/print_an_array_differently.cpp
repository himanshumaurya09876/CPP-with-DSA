#include <iostream>

using namespace std;

int main()
{
    int n,i,j=0;
    cout<<"Enter the size of array: ";
    cin>>n;
    int num[100];
    cout<<"Enter numbers in the array: "<<endl;
    for(i=0;i<n;i++)
    {
        cin>>num[i];
    }
    cout<<"Entered array is: ";
    for(i=0;i<n;i++)
    {
        cout<<num[i]<<" ";
    }
    cout<<endl;
    cout<<"Array printed in different way: ";
    for(i=0;i<n;i++,j++)
    {
        if(!(n&1) && i==n/2)
            j--;
        if(j&1)///odd
            cout<<num[i]<<" ";
        else///even
            cout<<num[n-i-1]<<" ";
    }
    cout<<endl;
    return 0;
}
