#include <iostream>

using namespace std;

int main()
{
    int n,n0=0,n1=0,n2=0;
    cout<<"Enter the size of arrays: ";
    cin>>n;
    int arr[100];
    cout<<"Enter the numbers"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        if(arr[i]==0)
            n0++;
        else if(arr[i]==1)
            n1++;
        else if(arr[i]==2)
            n2++;
        else
        {
            cout<<"Invalid input"<<endl;
            return 0;
        }
    }
    cout<<"Sorted array is: ";
    for(int i=0;i<n;i++)
    {
        if(i<n0)
            arr[i]=0;
        else if(n0<=i && i<n1+n0)
            arr[i]=1;
        else if(n1+n0<=i && i<n0+n1+n2)
            arr[i]=2;
        cout<<arr[i]<<" ";
    }
    return 0;
}
