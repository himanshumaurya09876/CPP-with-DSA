// RAT IN A MAZE
// You are given an N*M grid. Each cell (i,j) in the grid is either blocked, or empty. The rat can move from position (i,j), down or right on the grid.
// Initially rat is on the position (1,1). It wants to reach position (N,M). Find the rightmost path through which, rat can reach this position. A path is rightmost, if the rat is at position (i,j), it will always move to (i,j+1), if there exists a path from (i,j+1) to (N,M).

// Input Format:
// First line contains 2 integers, N and M, denoting the rows and columns in the grid. Next N line contains. M characters each. An 'X' in position (i,j) denotes that the cell is blocked and ans 'O' denotes that the cell is empty.

// Constraints:
// 1<=N,M<=1000 GRID(i,j)='X' or 'O'

// Output Format
// If a solution exists: Print N lines, containing M integers each. A 1 at a position (i,j) denotes that the (i,j)th cell is covered in the path and a 0 denotes that the cell is not covered in the path.
// If solution doesn't exist, just print "-1".

// Sample Input
// 5 4
// OXOO
// OOOX
// OOXO
// XOOO
// XXOO
// Sample Output
// 1 0 0 0 
// 1 1 0 0 
// 0 1 0 0 
// 0 1 1 1 
// 0 0 0 1 


#include<iostream>
using namespace std;

bool isSafe(char maze[][1001],int n,int m,int i,int j)
{
	if(i==n || j==m || maze[i][j]=='X')
	{
		return false;
	}
	return true;
}

bool findPathForRat(char maze[][1001],bool sol[][1001],int n,int m,int i=0,int j=0)
{
	if(i==n-1 && j==m-1)
	{
		if(isSafe(maze,n,m,i,j))
        {
            sol[i][j]=1;
		    return true;
        }
        else
        {
            return false;
        }
	}
	if(isSafe(maze,n,m,i,j))
	{
		sol[i][j]=1;
		if(findPathForRat(maze,sol,n,m,i,j+1))
		{
			return true;
		}
		if(findPathForRat(maze,sol,n,m,i+1,j))
		{
			return true;
		}
		sol[i][j]=0;
	}
	return false;
}

int main()
{
	char maze[1001][1001];
	bool sol[1001][1001]={0};
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>maze[i][j];
		}
	}
	if(findPathForRat(maze,sol,n,m))
	{
		for(int i=0;i<n;i++)
	 	{
			for(int j=0;j<m;j++)
			{
				cout<<sol[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	else
	{
		cout<<"-1"<<endl;
	}
	return 0;
}