#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n[100],n1[100],n2[100],c=0,s;
    cout<<"Enter the size of array: ";
    cin>>s;
    cout<<"Enter 10 numbers: "<<endl;
    for(int i=0;i<s;i++)
    {
        cin>>n[i];
    }
    cout<<"Entered numbers are: ";
    for(int i=0;i<s;i++)
    {
        cout<<n[i]<<" ";
    }
    cout<<endl;
    int maxn=INT_MIN;
    for(int i=s-1;i>=0;i--)
    {
        n1[i]=maxn;
        if(n[i]>maxn)
        {
            maxn=n[i];
        }
    }
    int minn=INT_MAX;
    for(int i=0;i<s;i++)
    {
        n2[i]=minn;
        if(n[i]<minn)
        {
            minn=n[i];
        }
    }
    cout<<"n1: ";
    for(int i=0;i<s;i++)
    {
        cout<<n1[i]<<" ";
    }
    cout<<endl;
    cout<<"n2: ";
    for(int i=0;i<s;i++)
    {
        cout<<n2[i]<<" ";
    }
    cout<<endl;
    cout<<"Obtained numbers are: ";
    for(int i=0;i<s;i++)
    {
        if(n2[i]>n[i] && n[i]>n1[i])
        {
            cout<<n[i]<<" ";
            c++;
        }
    }
    cout<<endl;
    cout<<"Final result is: "<<c<<endl;
    return 0;
}
