#include <iostream>

using namespace std;

int main()
{
    int n,maxsum=0,sum=0,p,q;
    cout <<"Enter the size of array: "<< endl;
    cin>>n;
    int arr[100];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i ;j<n;j++)
        {
            sum=0;
            for(int k=i;k<=j;k++)
            {
                sum+=arr[k];
            }
            if(maxsum<sum)
            {
                maxsum=sum;
                p=i;
                q=j;
            }
        }
    }
    cout<<"Maximum sum is: "<<maxsum<<endl;
    cout<<"Sub array is: ";
    for(int i=p;i<=q;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
