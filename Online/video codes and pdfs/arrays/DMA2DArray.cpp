#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int r,c;
	cin>>r>>c;
	int **arr=new int*[r];
	for(int i=0;i<r;i++)
	{
		arr[i]=new int[c];
	}
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			arr[i][j]=(i+1)*(j+1);
		}
	}
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}