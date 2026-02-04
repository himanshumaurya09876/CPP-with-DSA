//find a number in a circularly rotated array

#include<iostream>
using namespace std;
int findM(int n,int arr[],int m)
{
    int low=0,high=n-1;
    while(low<=high)
    {
        int mid=low+(high-low)/2; 
        if(m==arr[mid])
        {
            return mid;
        }
        else if(arr[low]<arr[mid])
        {
            if(m>=arr[low] && m<=arr[mid])
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        else if(arr[mid]<arr[high])
        {
             if(m>=arr[mid] && m<=arr[high])
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
    }
    return -1;
}

int main() {
    int n,m,arr[100000];
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cin>>m;
    cout<<findM(n,arr,m);
	return 0;
}