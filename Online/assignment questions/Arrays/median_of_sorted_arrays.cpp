//median of sorted arrays

#include<iostream>
using namespace std;
int median(int n,int arr1[],int arr2[])
{
    int n1=n-1,n2=n1+1,a,b,i=0,j=0,k=0;
    while(i<n && j<n)
    {
        if(arr1[i]<arr2[j])
        {
            if(n1==k)
            {
                a=arr1[i];
            }
            if(n2==k)
            {
                b=arr1[i];
                return (a+b)/2;
            }
            k++;
            i++;
        }
        else
        {
            if(n1==k)
            {
                a=arr2[j];
            }
            if(n2==k)
            {
                b=arr2[j];
                return (a+b)/2;
            }
            k++;
            j++;
        }
    }
    while(i<n)
    {
        if(n1==k)
        {
            a=arr1[i];
        }
        if(n2==k)
        {
            b=arr1[i];
            return (a+b)/2;
        }
        k++;
        i++;
    }
    while(j<n)
    {
        if(n1==k)
        {
            a=arr2[j];
        }
        if(n2==k)
        {
            b=arr2[j];
            return (a+b)/2;
        }
        k++;
        j++;
    }
    return 0;
}

int main() {
    int n,arr1[1000],arr2[1000];
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr1[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>arr2[i];
    }
    cout<<median(n,arr1,arr2);
    return 0;
}