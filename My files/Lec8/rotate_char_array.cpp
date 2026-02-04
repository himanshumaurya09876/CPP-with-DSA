#include <iostream>

using namespace std;

int main()
{
    int n,m;
    cout<<"Enter the size of array: ";
    cin>>n;
    char *arr=new char[n];
    cout<<"Enter the chars: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter from where to rotate: ";
    cin>>m;
    ///O(n*m)
    /*for(int i=0;i<m;i++)
    {
        char ch=arr[0];
        for(int j=0;j<n-1;j++)
        {
            arr[j]=arr[j+1];
        }
        arr[n-1]=ch;
    }*/
    ///O(n-m)
    int j=0,i;
    char temp;
    for(i=0;i<n-m;i++)
    {
        if(i<m)
        {
            temp=arr[i];
            arr[i]=arr[n-m+i];
            arr[n-m+i]=temp;
        }
        else
        {
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            j++;
        }
    }
    if(n%2==1)
    {
        i--;
        temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
        j++;
    }
    cout<<"After rotation we have: "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
