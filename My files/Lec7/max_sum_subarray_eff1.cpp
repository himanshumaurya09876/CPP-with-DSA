#include <iostream>

using namespace std;
///Kadane's algo
int main()
{
    int n,maxsum=0,csum=0,p=0,q=0,t=0;
    cout <<"Enter the size of array: "<< endl;
    cin>>n;
    int arr[100];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<n;i++)
    {
        csum+=arr[i];
        if(maxsum<csum)
        {
            maxsum=csum;
            q=i;
            p=t;
        }
        if(csum<0)
        {
            csum=0;
            t=i+1;
        }
    }
    cout<<"Max sum is: "<<maxsum<<endl;
    cout<<"Sub array is: ";
    for(int i=p;i<=q;i++)
        cout<<arr[i]<<" ";
    return 0;
}
