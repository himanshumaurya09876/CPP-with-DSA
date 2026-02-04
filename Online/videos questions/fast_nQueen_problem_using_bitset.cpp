//fast nQueen using bitset

#include <iostream>
#include <bitset>

using namespace std;

bitset<30> col,d1,d2;

void countNqueen(int n,int &count,int row=0)
{
	if(row==n)
	{
		count++;
		return;
	}
	for(int column=0;column<n;column++)
	{
		if(!col[column] && !d1[row-column+n-1] && !d2[row+column])
		{
			col[column]=d1[row-column+n-1]=d2[row+column]=1;
			countNqueen(n,count,row+1);
			col[column]=d1[row-column+n-1]=d2[row+column]=0;
		}
	}
}

void printNqueen(int sol[][30],int n,int row=0)
{
	if(row==n)
	{
		for(int a=0;a<n;a++)
		{
			for(int b=0;b<n;b++)
			{
				if(sol[a][b]==1)
                    cout<<"Q ";
                else
                    cout<<"_ ";
			}
			cout<<endl;
		}
		cout<<endl;
		return;
	}
	for(int column=0;column<n;column++)
	{
		if(!col[column] && !d1[row-column+n-1] && !d2[row+column])
		{
			col[column]=d1[row-column+n-1]=d2[row+column]=1;
			sol[row][column]=1;
			printNqueen(sol,n,row+1);
			col[column]=d1[row-column+n-1]=d2[row+column]=0;
			sol[row][column]=0;
		}
	}
}

int main()
{
	int n,count=0,sol[30][30]={0};
	cin>>n;
	countNqueen(n,count);
	cout<<"Total solutions: "<<count<<endl;
	cout<<"All solutions are: "<<endl;
	printNqueen(sol,n);
	return 0;
}
