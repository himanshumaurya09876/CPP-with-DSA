#include<iostream>
using namespace std;

void merge(int arr[],int first,int middle,int last)
{
    int n1=middle-first+1,n2=last-middle,arr1[100000],arr2[100000],i,j,k;
    for(i=0;i<n1;i++)
    {
        arr1[i]=arr[first+i];
    }
    for(j=0;j<n2;j++)
    {
        arr2[j]=arr[middle+j+1];
    }
    i=0;
    j=0;
    k=0;
    while(i<n1 && j<n2)
    {
        if(arr1[i]<arr2[j])
        {
            arr[k+first]=arr1[i];
            k++;
            i++;
        }
        else
        {
            arr[k+first]=arr2[j];
            k++;
            j++;
        }
    }
    while(i<n1)
    {
        arr[k+first]=arr1[i];
        k++;
        i++;
    }
    while(j<n2)
    {
        arr[k+first]=arr2[j];
        k++;
        j++;
    }
}

void mergesort(int arr[],int first,int last)
{
    if(first>=last)
    {
        return;
    }
    int mid=(first+last)/2;
    mergesort(arr,first,mid);
    mergesort(arr,mid+1,last);
    merge(arr,first,mid,last);
}

int main()
{
    int n,arr[200000];
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    mergesort(arr,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
	return 0;
}
