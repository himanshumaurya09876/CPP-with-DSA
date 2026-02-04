//greatest rectangular area having 1s in a 2D matrix
#include <iostream>
#include <stack>
using namespace std;

int greatestArea(int arr[][10],int r,int c)
{

}

int main(int argc, char const *argv[])
{
	int arr[5][8]={{0,1,1,1,0,1,0,1},
				   {1,0,1,1,1,1,1,1},
				   {0,1,1,1,1,1,0,1},
				   {1,1,1,1,1,1,1,1},
				   {0,1,1,0,1,0,1,0}};
	int r=sizeof(arr)/sizeof(arr[0]);
	int c=sizeof(arr)/(sizeof(arr[0][0])*r);
	cout<<greatestArea(arr,r,c)<<endl;
	return 0;
}