#include <iostream>

using namespace std;

void merge(int *arr,int s,int m,int e)
{
    int arr1[m-s+1];
    int arr2[e-m];
    int i,j,k=s;
    for(i=0;i<m-s+1;i++)
    {
        arr1[i]=*(arr+i+s);
    }
    for(i=0;i<e-m;i++)
    {
        arr2[i]=*(arr+i+m+1);
    }
    i=0;
    j=0;
    while(i<m-s+1 && j<e-m)
    {
        if(arr1[i]<arr2[j])
        {
            *(arr+k)=arr1[i];
            k++;
            i++;
        }
        else
        {
            *(arr+k)=arr2[j];
            k++;
            j++;
        }
    }
    while(i<m-s)
    {
        *(arr+k)=arr1[i];
        k++;
        i++;
    }
    while(j<e-m)
    {
        *(arr+k)=arr2[j];
        k++;
        j++;
    }
}

void mergesort(int *arr,int s,int e)
{
    if(s>=e)//Base case
        return;
    int m=(s+e)/2;
    mergesort(arr,s,m);
    mergesort(arr,m+1,e);
    merge(arr,s,m,e);
}

int main()
{
    int arr[10]={1,2,5,101,4,8,9,200,86,99};
    mergesort(arr,0,9);
    cout<<"Sorted array is: ";
    for(int i=0;i<10;i++)
    {
        cout<<*(arr+i)<<" ";
    }
    return 0;
}
