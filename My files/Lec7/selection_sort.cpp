#include <iostream>

using namespace std;

int main()
{
    int n,minidx;
    cout<<"Enter the size: ";
    cin>>n;
    int arr[100];
    cout<<"Enter the numbers: "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<n-1;i++)
    {
        minidx=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[minidx])
            {
                minidx=j;
            }
        }
        int temp=arr[i];
        arr[i]=arr[minidx];
        arr[minidx]=temp;
    }
    cout<<"Sorted array is: ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
