//calculate maximum rectangular area of histogram
#include <iostream>
#include <stack>
using namespace std;
 
int calMaxArea(int arr[],int n){
	stack<int> indices;
	int maxArea=0;
	indices.push(1);
	for(int i=1;i<n;i++){
		if(arr[i]>=arr[indices.top()])
		{
			indices.push(i);
		}
		else
		{
			while(!indices.empty() && arr[i]<arr[indices.top()])
			{
				int left,right;
				right=i-1;
				int popNum=arr[indices.top()];
				indices.pop();
				if(indices.empty())
				{
					left=0;
				}
				else
				{
					left=indices.top();
				}
				int width=right-left;
				maxArea=max(maxArea,width*popNum);
			}
			indices.push(i);
		}
	}
	while(!indices.empty())
	{
		int left,right;
		right=n-1;
		int popNum=arr[indices.top()];
		indices.pop();
		if(indices.empty())
		{
			left=0;
		}
		else
		{
			left=indices.top();
		}
		int width=right-left;
		maxArea=max(maxArea,width*popNum);
	}
	return maxArea;
}
 
int main(){
	//int arr[]={0,1,3,2,3,5,4,3};
	int arr[]={0,3,2,1,5,5,6,2,3};
	int n=sizeof(arr)/sizeof(arr[0]);
	cout<<calMaxArea(arr,n)<<endl;
	return 0;
}