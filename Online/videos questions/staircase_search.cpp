//staircase search
#include <iostream>

using namespace std;

bool search(int mat[][50],int m,int n,int num)
{
	int r=0,c=n-1;//or you can also traverse with r=m-1,c=0
	while(r<m && c>=0)
	{
		if(mat[r][c]==num)
		{
			return true;
		}
		else if(mat[r][c]>num)
		{
			c--;
		}
		else
		{
			r++;
		}
	}
	return false;
}

int main(int argc, char const *argv[])
{
	int mat[50][50]={0};
	int m,n,num;
	cin>>m>>n;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>mat[i][j];
		}
	}
	cin>>num;
	if(search(mat,m,n,num))
	{
		cout<<num<<" found in the matrix"<<endl;
	}
	else
	{
		cout<<num<<" does not found in the matrix"<<endl;
	}
	return 0;
}