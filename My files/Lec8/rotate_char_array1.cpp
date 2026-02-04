#include <iostream>

using namespace std;

int main()
{
    int n,k;
    cout<<"Enter the size of array: ";
    cin>>n;
    char *arr=new char[n+1];
    cout<<"Enter array: ";
    cin>>arr;
    arr[n+1]='\0';
    cout<<"Enter from where to rotate: ";
    cin>>k;
    ///O(n)
    char *arr1=new char[k];
    for(int i=0;i<k;i++)
    {
        arr1[i]=arr[i];
    }
    int j=0;
    for(int i=0;i<n;i++)
    {
        if(i<n-k)
        {
            arr[i]=arr[i+k];
        }
        else
        {
            arr[i]=arr1[j];
            j++;
        }
    }
    cout<<"After rotation we have: "<<arr;
    return 0;
}
