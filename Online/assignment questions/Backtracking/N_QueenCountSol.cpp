// Total Count of N-Queen solutions
// COUNT N-QUEEN
// You are given an empty chess board of size N*N. Find the number of ways to place N queens on the board, such that no two queens can kill each other in one move. A queen can move vertically, horizontally and diagonally.

// Input Format:
// A single integer N, denoting the size of chess board.

// Constraints:
// 1<=N<=11

// Output Format
// A single integer denoting the count of solutions.

// Sample Input
// 4
// Sample Output
// 2
#include <iostream>
using namespace std;

bool isSafe(int mat[][11],int n,int i,int j)
{
	//left upper diagonal
	for(int x=i-1,y=j-1;x>=0 && y>=0;x--,y--)
	{
		if(mat[x][y]==1)
		{
			return false;
		}
	}
	//upper column
	for(int x=i-1;x>=0;x--)
	{
		if(mat[x][j]==1)
		{
			return false;
		}
	}
	//right upper diagonal
	for(int x=i-1,y=j+1;x>=0 && y<n;x--,y++)
	{
		if(mat[x][y]==1)
		{
			return false;
		}
	}
	return true;
}

int solveN_Queen(int mat[][11],int n,int r=0)
{
	if(r==n)
	{
		// for(int i=0;i<n;i++)
		// {
		// 	for(int j=0;j<n;j++)
		// 	{
		// 		if(mat[i][j]==1)
		// 		{
		// 			cout<<"Q ";
		// 		}
		// 		else
		// 		{
		// 			cout<<"_ ";
		// 		}
		// 	}
		// 	cout<<endl;
		// }
		// cout<<"====================="<<endl;
		return 1;
	}
	int count=0;
	for(int i=0;i<n;i++)
	{
		if(isSafe(mat,n,r,i))
		{
			mat[r][i]=1;
			count+=solveN_Queen(mat,n,r+1);
			mat[r][i]=0;
		}
	}
	return count;
}

int main(int argc, char const *argv[])
{
	int n,mat[11][11]={0};
	cin>>n;
	cout<<solveN_Queen(mat,n);
	return 0;
}