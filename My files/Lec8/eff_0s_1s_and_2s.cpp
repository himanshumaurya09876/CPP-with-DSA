#include <iostream>

using namespace std;
///Dutch National Flag (DNF) Algo
int main()
{
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int arr[100];
    cout<<"Enter the numbers"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int low=0,mid=0,high=n-1;
    while(mid<=high)
    {
        int temp;
        if(arr[mid]==2)
        {
            temp=arr[high];
            arr[high]=arr[mid];
            arr[mid]=temp;
            high--;
        }
        else if(arr[mid]==0)
        {
            temp=arr[low];
            arr[low]=arr[mid];
            arr[mid]=temp;
            low++;
            mid++;
        }
        else
            mid++;
    }
    cout<<"Sorted array is: ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
