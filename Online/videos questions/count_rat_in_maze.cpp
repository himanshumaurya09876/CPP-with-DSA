//count total number of solutions of rat in a maze using recursiom and backtracking

#include <iostream>

using namespace std;

int ratMaze(int maze[4][5],int row,int col,int i=0,int j=0)
{
	int res=0;
	if(i==row && j==col)
	{
		return 1;
	}
	if(maze[i][j]==1 || i>row || j>col)
	{
		return 0;
	}
	res=ratMaze(maze,row,col,i,j+1)+ratMaze(maze,row,col,i+1,j);
	return res;
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
	cout<<"No. of solution is: "<<ratMaze(maze,3,4);
	return 0;
}