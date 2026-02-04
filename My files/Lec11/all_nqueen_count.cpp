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

int nqueen(int maze[10][10],int n,int r=0)
{
    int i,count=0;
    if(r==n)
    {
        return 1;
    }
    for(i=0;i<n;i++)
    {
        if(isSafe(maze,r,i,n))
        {
            maze[r][i]=1;
            int res=nqueen(maze,n,r+1);
            count+=res;
            if(count)
            {
                return count;
            }
            else
            {
                maze[r][i]=0;
            }
        }
    }
    return 0;
}

int main()
{
    int maze[10][10];
    int n;
    cout<<"Enter size of maze: ";
    cin>>n;
    cout<<"Total possible combinations are: "<<nqueen(maze,n);
    return 0;
}
