#include <iostream>

using namespace std;

int main()
{
    int n,r,i,k=0,num[100],num1[100];
    cout<<"Enter the size of list: ";
    cin>>n;
    cout<<"Enter the numbers in the list:"<<endl;
    for(i=0;i<n;i++)
    {
        cin>>num[i];
    }
    cout<<"List you made is: ";
    for(i=0;i<n;i++)
    {
        cout<<num[i]<<" ";
    }
    cout<<endl;
    cout<<"Enter how many nos. in list you want to rotate: ";
    cin>>r;
    for(i=n-r;i<n;i++,k++)
    {
        num1[k]=num[i];
    }
    for(i=0;i<n-r;i++,k++)
    {
        num1[k]=num[i];
    }
    cout<<"List after rotation becomes: ";
    for(i=0;i<n;i++)
    {
        cout<<num1[i]<<" ";
    }
    cout<<endl;
    return 0;
}
