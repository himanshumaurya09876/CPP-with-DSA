#include <iostream>
#include <string>

using namespace std;

bool isSafe(int maze[10][10],int i,int j,int n)
{
    int k,l;
    for(k=i-1,l=j-1; k>=0 && l>=0; k--,l--)
    {
        if(maze[k][l]==1)
            return false;
    }
    for(k=i-1; k>=0; k--)
    {
        if(maze[k][j]==1)
            return false;
    }
    for(k=i-1,l=j+1; k>=0 && l<=n-1; k--,l++)
    {
        if(maze[k][l]==1)
            return false;
    }
    return true;
}

bool nqueen(int maze[10][10],int n,int r=0)
{
    int i;
    if(r==n)
    {
        for(i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(maze[i][j]==1)
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
        cout<<"********************************************"<<endl;
        return false;
    }
    for(i=0;i<n;i++)
    {
        if(isSafe(maze,r,i,n))
        {
            maze[r][i]=1;
            if(nqueen(maze,n,r+1))
            {
                return true;
            }
            else
            {
                maze[r][i]=0;
            }
        }
    }
    return false;
}

int main()
{
    int maze[10][10];
    int n;
    cout<<"Enter size of maze: ";
    cin>>n;
    nqueen(maze,n);
    return 0;
}
