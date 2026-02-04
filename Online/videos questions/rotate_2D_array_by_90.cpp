//rotate a 2D array by 90 degrees(in place rotation ie in O(1))

#include <iostream>

using namespace std;

void rotateBy90(int mat[3][3],int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			int temp=mat[i][j];
			mat[i][j]=mat[j][i];
			mat[j][i]=temp;
		}
	}
	for(int i=0;i<n;i++)
	{
		int first=0,last=n-1;
		while(first<last)
		{
			int temp=mat[i][first];
			mat[i][first]=mat[i][last];
			mat[i][last]=temp;
			first++;
			last--;
		}
	}
}

int main()
{
	int mat[3][3]={{1,2,3},
				   {4,5,6},
				   {7,8,9}};
	int n=3;
	rotateBy90(mat,n);
	cout<<"Rotated matrix is: "<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}