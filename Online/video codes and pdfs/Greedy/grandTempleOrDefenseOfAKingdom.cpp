// GRAND TEMPLE (similar to DEFENSE OF A KINGDOM)
// A religious king wants to build the largest temple in his kingdom . To build the largest temple he needs to find the area of the largest suitable land . Given co-ordinates which denotes rivers flowing through the point horizontally as well as vertically , find the largest area possible to make the grand temple.
// pic

// Input Format:
// An integer n denoting number of co-ordinates followed by n co-ordinates

// Constraints:
// 1 <= N <= 10^5 | Ai | <= 10^9

// Output Format
// Largest possible area to build the grand temple

// Sample Input
// 3
// 1 1
// 2 4
// 5 2
// Sample Output
// 2

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int *x=new int[n];
	int *y=new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>x[i]>>y[i];
	}

	sort(x,x+n);
	sort(y,y+n);

	int maxDx=0;
	int maxDy=0;
	for(int i=1;i<n;i++)
	{
		maxDx=max(maxDx,x[i]-x[i-1]-1);
		maxDy=max(maxDy,y[i]-y[i-1]-1);
	}

	cout<<maxDy*maxDx<<endl;
	return 0;
}
