
// SUDOKU SOLVER
// You are given an N*N sudoku grid (N is a multiple of 3). Solve the sudoku and print the solution.
// To learn more about sudoku, go to this link Sudoku-Wikipedia.

// Input Format:
// First line contains a single integer N. Next N lines contains N integers each, where jth integer int ith line denotes the value at ith row and jth column in sudoku grid. This value is 0, if the cell is empty.

// Constraints:
// N=9 Solution exists for input matrix.

// Output Format
// Print N lines containing N integers each, where jth integer int ith line denotes the value at ith row and jth column in sudoku grid, such that all cells are filled.

// Sample Input
// 9
// 5 3 0 0 7 0 0 0 0 
// 6 0 0 1 9 5 0 0 0 
// 0 9 8 0 0 0 0 6 0 
// 8 0 0 0 6 0 0 0 3 
// 4 0 0 8 0 3 0 0 1 
// 7 0 0 0 2 0 0 0 6 
// 0 6 0 0 0 0 2 8 0 
// 0 0 0 4 1 9 0 0 5 
// 0 0 0 0 8 0 0 7 9
// Sample Output
// 5 3 4 6 7 8 9 1 2 
// 6 7 2 1 9 5 3 4 8 
// 1 9 8 3 4 2 5 6 7 
// 8 5 9 7 6 1 4 2 3 
// 4 2 6 8 5 3 7 9 1 
// 7 1 3 9 2 4 8 5 6 
// 9 6 1 5 3 7 2 8 4 
// 2 8 7 4 1 9 6 3 5 
// 3 4 5 2 8 6 1 7 9 

#include <iostream>
#include <cmath>

using namespace std;
bool isPossible(int mat[][9],int n,int i,int j,int num)
{
	for(int x=0;x<n;x++)
	{
		if(mat[i][x]==num || mat[x][j]==num)
		{
			return false;
		}
	}
	int root=sqrt(n);
	int subgrid_x=(i/root)*root;
	int subgrid_y=(j/root)*root;
	for(int x=subgrid_x;x<root+subgrid_x;x++)
	{
		for(int y=subgrid_y;y<root+subgrid_y;y++)
		{
			if(mat[x][y]==num)
			{
				return false;
			}
		}
	}
	return true;
}

bool solveSudoku(int mat[][9],int n,int i=0,int j=0)
{
	//base case
	if(i==n)
	{
		// for(int x=0;x<n;x++)
		// {
		// 	for(int y=0;y<n;y++)
		// 	{
		// 		cout<<mat[x][y]<<" ";
		// 	}
		// 	cout<<endl;
		// }
		return true;
	}
	if(j==n)
	{
		return solveSudoku(mat,n,i+1,0);
	}

	if(mat[i][j]!=0)
	{
		return solveSudoku(mat,n,i,j+1);
	}
	for(int num=1;num<=n;num++)
	{
		if(isPossible(mat,n,i,j,num))
		{
			mat[i][j]=num;
			bool isFilled=solveSudoku(mat,n,i,j+1);
			if(isFilled)
			{
				return true;
			}
		}
	}
	mat[i][j]=0;
	return false;
}

int main(int argc, char const *argv[])
{
	int mat[9][9]={0},n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>mat[i][j];
		}
	}
	solveSudoku(mat,n);
	for(int x=0;x<n;x++)
	{
		for(int y=0;y<n;y++)
		{
			cout<<mat[x][y]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
