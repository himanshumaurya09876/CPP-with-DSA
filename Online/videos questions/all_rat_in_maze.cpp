//All solutions of rat in a maze using recursiom and backtracking

#include <iostream>

using namespace std;

/*bool ratMaze(int maze[4][5],int sol[4][5],int row,int col,int i=0,int j=0)
{
	if(i==row && j==col)
	{
		sol[i][j]=1;
		for(int a=0;a<=row;a++)
		{
			for(int b=0;b<=col;b++)
			{
				cout<<sol[a][b]<<" ";
			}
			cout<<endl;
		}
		cout<<endl<<endl;
		return false;
	}
	if(maze[i][j]==1 || i>row || j>col)
	{
		return false;
	}
	sol[i][j]=1;
	bool right=ratMaze(maze,sol,row,col,i,j+1);
	if(right)
	{
		return true;
	}
	bool down=ratMaze(maze,sol,row,col,i+1,j);
	if(down)
	{
		return true;
	}
	sol[i][j]=0;
	return false;
}*/

void ratMaze(int maze[4][5],int sol[4][5],int row,int col,int i=0,int j=0)
{
	if(i==row && j==col)
	{
		sol[i][j]=1;
		for(int a=0;a<=row;a++)
		{
			for(int b=0;b<=col;b++)
			{
				cout<<sol[a][b]<<" ";
			}
			cout<<endl;
		}
		cout<<endl<<endl;
		return;
	}
	if(maze[i][j]==1 || i>row || j>col)
	{
		return;
	}
	sol[i][j]=1;
	ratMaze(maze,sol,row,col,i,j+1);
	ratMaze(maze,sol,row,col,i+1,j);
	sol[i][j]=0;
	return;
}

int main()
{
	int maze[4][5]={{0,0,0,1,0},
				    {0,0,0,0,0},
				    {0,1,0,1,0},
				    {1,1,1,0,0}};
	cout<<"Your maze is"<<endl;
	for(int a=0;a<4;a++)
	{
		for(int b=0;b<5;b++)
		{
			cout<<maze[a][b]<<" ";
		}
		cout<<endl;
	}
	cout<<"Solution is"<<endl;
	int sol[4][5]={0};
	ratMaze(maze,sol,3,4);
	return 0;
}