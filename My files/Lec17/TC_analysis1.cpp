//time complexity analysis 
// #include <iostream>
// #include <algorithm>

#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[],int n)
{
	for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

int main()
{
	int arr[100000],n=100000;
	for(int i=0;i<n;i++)
	{
		arr[i]=n-i;
	}
	clock_t start,end;
	// start=clock();
	// bubbleSort(arr,n);
	// end=clock();
	// cout<<"Time taken by bubble sort "<<end-start<<endl;
	// for(int i=0;i<n;i++)
	// {
	// 	arr[i]=n-i;
	// }
	start=clock();
	sort(arr,arr+n);
	end=clock();
	cout<<"Time taken by inbuilt sort "<<end-start<<endl;
	return 0;
}