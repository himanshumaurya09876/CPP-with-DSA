//nQueen problem

#include <iostream>

using namespace std;

bool isSafe(int arr[][10],int n,int row,int col)
{
	int i,j;
	//check for upper left diagonal
	for(i=row-1,j=col-1;i>=0 && j>=0;i--,j--)
	{
		if(arr[i][j]==1)
		{
			return false;
		}
	}

	//check for upper right diagonal
	for(i=row-1,j=col+1;i>=0 && j<n;i--,j++)
	{
		if(arr[i][j]==1)
		{
			return false;
		}
	}

	//check for upper column
	for(i=row-1;i>=0;i--)
	{
		if(arr[i][col]==1)
		{
			return false;
		}
	}

	return true;
}

bool nQueenSolve(int arr[][10],int n,int i=0)
{
	//base case
	if(i==n)
	{
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<n;k++)
			{
				if(arr[j][k]==1)
				{
					cout<<"Q ";
				}
				else
				{
					cout<<"_ ";
				}
			}
			cout<<endl;
		}
		return true;
	}
	//recursive case
	for(int j=0;j<n;j++)
	{
		if(isSafe(arr,n,i,j))
		{
			arr[i][j]=1;
			bool res=nQueenSolve(arr,n,i+1);
			//backtracking
			if(res)
				return true;
			arr[i][j]=0;
		}
	}
	return false;
}

int main()
{
	int n,arr[10][10]={0};
	cin>>n;
	nQueenSolve(arr,n);
	return 0;
}