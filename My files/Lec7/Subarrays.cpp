#include <iostream>

using namespace std;

int main()
{
    int n;
    cout <<"Enter the size of array: "<< endl;
    cin>>n;
    int arr[100];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Sub arrays are: "<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=i ;j<n;j++)
        {
            for(int k=i;k<=j;k++)
            {
                cout<<arr[k]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
