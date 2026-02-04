#include <iostream>

using namespace std;

char flag;

bool isSafe(int maze[10][10],int i,int j,int r,int c)
{
    if(j>=c || i>=r || maze[i][j]==1)
        return false;
    else
        return true;
}

bool rate_in_maze(int maze[10][10],int sol[10][10],int r,int c,int i=0,int j=0)
{
    if(maze[r-1][c-1]==1)
    {
        return false;
    }
    if(i==r-1 && j==c-1)
    {
        flag='y';
        sol[i][j]=1;
        cout<<"Final path is- "<<endl;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                cout<<sol[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<"****************************************************************"<<endl;
        return false;
    }
    if(isSafe(maze,i,j,r,c))
    {
        sol[i][j]=1;
        bool resright=rate_in_maze(maze,sol,r,c,i,j+1);
        if(resright)
        {
            return true;
        }
        bool resdown=rate_in_maze(maze,sol,r,c,i+1,j);
        if(resdown)
        {
            return true;
        }
        sol[i][j]=0;
    }
    return false;
}

int main()
{
    int maze[10][10],sol[10][10]={0},r,c;
    cout<<"Enter the size of maze: "<<endl;
    cin>>r>>c;
    cout<<"Enter maze: "<<endl;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin>>maze[i][j];
        }
    }
    bool res=rate_in_maze(maze,sol,r,c);
    /*if(res)
    {
        cout<<"Final path is- "<<endl;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                cout<<sol[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    else
    {
        cout<<"No path exist"<<endl;
    }*/
    if(flag!='y')
    {
        cout<<"No path exist"<<endl;
    }
    return 0;
}
