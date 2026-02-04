#include <iostream>

using namespace std;

int linsearch(int arr[],int s,int n,int i=0)
{
    if(n==arr[i])
    {
        return i;
    }
    else if(i>=s)
    {
        return -1;
    }
    else
    {
        return (linsearch(arr,s,n,i+1));
    }
}

int main()
{
    int arr[100],i,n,j,s;
    cout<<"Enter size of array: ";
    cin>>s;
    cout<<"Enter "<<s<<" numbers: ";
    for(i=0;i<s;i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter number to be searched: ";
    cin>>n;
    j=linsearch(arr,s,n);
    if(j==-1)
    {
        cout<<n<<" does not found."<<endl;
    }
    else
    {
        cout<<n<<" found at index "<<j<<endl;
    }
    return 0;
}
