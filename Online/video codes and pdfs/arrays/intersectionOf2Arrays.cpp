#include<iostream>
using namespace std;
int main()
{
    int n,a[1000],b[1000],c[1000],k=0;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    for(int i=0; i<=n-2; i++)
    {
        for( int j=0; j<=n-2-i; j++)
        {
            if (a[j]>a[j+1])
            {
                int temp = a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    for(int i=0; i<n; i++)
    {
        cin>>b[i];
    }
    for(int i=0; i<=n-2; i++)
    {
        for( int j=0; j<=n-2-i; j++)
        {
            if (b[j]>b[j+1])
            {
                int temp = b[j];
                b[j]=b[j+1];
                b[j+1]=temp;
            }
        }
    }

    // for(int i=0; i<n; i++)
    // {
    //     cout<<a[i]<<" ";
    // }
    // cout<<endl;
    // for(int i=0; i<n; i++)
    // {
    //     cout<<b[i]<<" ";
    // }

    for(int i=0, j=0; i<n && j<n;)
    {
        if(a[i]==b[j])
        {
            c[k]=a[i];
            i++;
            j++;
            k++;
        }
        else if(a[i]<b[j])
        {
            i++;
        }
        else
        {
            j++;
        }

    }

    cout<<"["<<c[0];
    for(int i=1; i<k; i++)
    {
        cout<<","<<" "<<c[i];

    }
    cout<<"]";

    return 0;
}