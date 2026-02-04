// FUNKY CHESS BOARD
// A knight is a piece used in the game of chess. The chessboard itself is square array of cells. Each time a knight moves, its resulting position is two rows and one column, or two columns and one row away from its starting position. Thus a knight starting on row r, column c – which we’ll denote as (r,c) – can move to any of the squares (r-2,c-1), (r-2,c+1), (r-1,c-2), (r-1,c+2), (r+1,c-2), (r+1,c+2), (r+2,c-1), or (r+2,c+1). Of course, the knight may not move to any square that is not on the board.

// Suppose the chessboard is not square, but instead has rows with variable numbers of columns, and with each row offset zero or more columns to the right of the row above it. The figure to the left illustrates one possible configuration. How many of the squares in such a modified chessboard can a knight, starting in the upper left square (marked with an asterisk), not reach in any number of moves without resting in any square more than once? Minimize this number.

// Imgur

// If necessary, the knight is permitted to pass over regions that are outside the borders of the modified chessboard, but as usual, it can only move to squares that are within the borders of the board.

// Input Format:
// First line contains an integer n, representing the side of square of chess board. The next n line contains n integers separated by single spaces in which jjth integer is 1 if that cell(i,j) is part of chessboard and 0 otherwise.

// Constraints:
// The maximum dimensions of the board will be 10 rows and 10 columns. That is, any modified chessboard specified by the input will fit completely on a 10 row, 10 column board.

// Output Format
// Print the minimum number of squares that the knight can not reach.

// Sample Input
// 3
// 1 1 1
// 1 1 1
// 1 1 1
// Sample Output
// 1

#include <iostream>
using namespace std;

// bool isPossible(int arr[][10],int n,int i,int j)
// {
// 	if(i>=0 && j>=0 && i<n && j<n && arr[i][j]==1)
// 	{
// 		return true;
// 	}
// 	return false;
// }

int findCanBeVisited(int arr[][10],int n,int i=0,int j=0)
{
	// if(!isPossible(arr,n,i,j))
	// {
	// 	return 0;
	// }
	if(!(i>=0 && j>=0 && i<n && j<n && arr[i][j]==1))
	{
		return 0;
	}
	arr[i][j]=0;
	int max=0;
	int res=findCanBeVisited(arr,n,i-2,j-1);
	if(max<res)
	{
		max=res;
	}
	res=findCanBeVisited(arr,n,i-2,j+1);
	if(max<res)
	{
		max=res;
	}
	res=findCanBeVisited(arr,n,i-1,j+2);
	if(max<res)
	{
		max=res;
	}
	res=findCanBeVisited(arr,n,i+1,j+2);
	if(max<res)
	{
		max=res;
	}
	res=findCanBeVisited(arr,n,i+2,j+1);
	if(max<res)
	{
		max=res;
	}
	res=findCanBeVisited(arr,n,i+2,j-1);
	if(max<res)
	{
		max=res;
	}
	res=findCanBeVisited(arr,n,i+1,j-2);
	if(max<res)
	{
		max=res;
	}
	res=findCanBeVisited(arr,n,i-1,j-2);
	if(max<res)
	{
		max=res;
	}
	arr[i][j]=1;
	return max+1;
}

int main(int argc, char const *argv[])
{
	int n,arr[10][10]={0},total=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>arr[i][j];
			if(arr[i][j]==1)
			{
				total++;
			}
		}
	}
	cout<<total-findCanBeVisited(arr,n)<<endl;
	return 0;
}