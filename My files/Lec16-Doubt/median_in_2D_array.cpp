 //find median in 2D array having sorted rows but unsorted columns
#include <bits/stdc++.h>

using namespace std;

int findMedian(int mat[][5],int r,int c)
{
	int low=INT_MAX,high=INT_MIN;
	for(int i=0;i<r;i++)
	{
		if(low>mat[i][0])
		{
			low=mat[i][0];
		}
		if(high<mat[i][c-1])
		{
			high=mat[i][c-1];
		}
	}
	while(low<=high)
	{
		int mid=low+(high-low)/2;
		int uppercount=0,medpos=(r*c)/2;
		for(int i=0;i<r;i++)
		{
			int num=upper_bound(mat[i],mat[i]+c,mid)-&mat[i][0];
			uppercount+=num;
		}
		cout<<low<<" "<<high<<endl;
		cout<<mid<<" "<<uppercount<<" "<<medpos<<endl;
		if(uppercount==medpos)
		{
			int ans=INT_MAX;
			for(int i=0;i<r;i++)
			{
				int first=0,last=c-1;
				while(first<=last)
				{
					int middle=first+(last-first)/2;
					if(mid==mat[i][middle])
					{
						return mid;
					}
					else if(mid<mat[i][middle])
					{
						last=middle-1;
					}
					else
					{
						first=middle+1;
					}
				}
				if(abs(ans-mid)>abs(mat[i][first]-mid))
				{
					ans=mat[i][first];
				}
			}
			return ans;
		}
		else if(uppercount<medpos)
		{
			low=mid+1;
		}
		else
		{
			high=mid-1;
		}
	}
	return 0;
}

int main()
{
	int mat[5][5]={{4,5,9,32,69},
				   {2,13,25,36,45},
				   {11,31,51,63,71},
				   {20,54,78,99,150},
				   {3,16,17,41,0}};
	int r=5,c=5;
	int arr[25]={4,5,9,32,69,2,13,25,36,45,11,31,51,63,71,20,54,78,99,150,3,16,17,41,895};
	cout<<findMedian(mat,r,c)<<endl;
	sort(arr,arr+25);
	cout<<arr[12]<<endl;
	return 0;
}
