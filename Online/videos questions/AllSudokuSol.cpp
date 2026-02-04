//Sudoku solver

#include <iostream>
#include <cmath>

using namespace std;

bool canPlace(int Sudoku[][9],int n,int i,int j,int num)
{
	for(int x=0;x<n;x++)
	{
		if(num==Sudoku[i][x] || num==Sudoku[x][j])
		{
			return false;
		}
	}
	int rn=sqrt(n);
	int sx=(i/rn)*rn;
	int sy=(j/rn)*rn;
	for(int x=sx;x<sx+3;x++)
	{
		for(int y=sy;y<sy+3;y++)
		{
			if(num==Sudoku[x][y])
			{
				return false;
			}
		}
	}
	return true;
}

bool SudokuSolver(int Sudoku[][9],int n,int i=0,int j=0)
{
	//base case
	if(i==n)
	{
		//print Sudoku
		for(int x=0;x<n;x++)
		{
			for(int y=0;y<n;y++)
			{
				cout<<Sudoku[x][y]<<" ";
			}
			cout<<endl;
		}
		cout<<"____________________"<<endl;
		return false;
	}
	//when the row ends
	if(j==n)
	{
		return SudokuSolver(Sudoku,n,i+1,0);
	}
	//if the cell is already filled then skip it
	if(Sudoku[i][j]!=0)
	{
		return SudokuSolver(Sudoku,n,i,j+1);
	}
	//recursive case
	for(int x=1;x<=n;x++)
	{
		if(canPlace(Sudoku,n,i,j,x))
		{
			Sudoku[i][j]=x;
			bool couldPlace=SudokuSolver(Sudoku,n,i,j+1);
			if(couldPlace)
			{
				return true;
			}
		}
	}
	//backtracking case
	Sudoku[i][j]=0;
	return false;
}

int main(int argc, char const *argv[])
{
	int Sudoku[9][9]={{9,0,6,0,7,0,4,0,3},
					  {0,0,0,4,0,0,2,0,0},
					  {0,7,0,0,2,3,0,1,0},
					  {5,0,0,0,0,0,1,0,0},
					  {0,4,0,2,0,8,0,6,0},
					  {0,0,3,0,0,0,0,0,5},
					  {0,3,0,7,0,0,0,5,0},
					  {0,0,7,0,0,5,0,0,0},
					  {8,0,1,0,0,6,5,4,0}};
	int n=9;
	SudokuSolver(Sudoku,n);
	return 0;
}