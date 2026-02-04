//Given a brick wall of 4XN, and tiles of 4X1.You  have to find total no. of ways to arrange tiles on the wall.
#include <iostream>

using namespace std;

int arrangeTiles(int n)
{
	if(n==4)
	{
		return 2;
	}
	else if(n<4)
	{
		return 1;
	}
	return (arrangeTiles(n-1)+arrangeTiles(n-4));
}

int main()
{
	int n;
	cout<<"Enter the value of N for NX4(area) wall: ";
	cin>>n;
	cout<<"Total no. of ways are: "<<arrangeTiles(n);
	return 0;
}