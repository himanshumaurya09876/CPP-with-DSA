//counting sort

#include<bits/stdc++.h>
using namespace std;
void countingSort(int arr[],int n)
{
    int max=INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(max<arr[i])
        {
            max=arr[i];
        }
    }
    int *freqArr=new int[max+1]();
    for(int i=0;i<n;i++)
    {
        freqArr[arr[i]]++;
    }
    int j=0;
    for(int i=0;i<=max;i++)
    {
        while(freqArr[i]>0)
        {
            arr[j]=i;
            j++;
            freqArr[i]--;
        }
    }
}
int main() {
    int n,arr[1000000];
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    countingSort(arr,n);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
	return 0;
}