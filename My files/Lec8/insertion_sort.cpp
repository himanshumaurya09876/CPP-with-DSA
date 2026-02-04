#include <iostream>

using namespace std;

int main()
{
    int n;
    cout<<"Enter the size: ";
    cin>>n;
    int arr[100];
    cout<<"Enter the numbers: "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i=1;i<n;i++)
    {
        int j=i-1;
        while(j>=0 && arr[j]>arr[j+1])
        {
            int temp;
            temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
            j--;
        }
    }
    cout<<"Sorted array is: ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
