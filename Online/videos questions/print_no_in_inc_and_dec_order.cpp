#include <iostream>

using namespace std;

void printDec(int n)
{
	cout<<n<<" ";
	if(n==0)
	{
		return;
	}
	printDec(n-1);
}

void printInc(int n)
{
	if(n==-1)
	{
		return;
	}
	printInc(n-1);
	cout<<n<<" ";
}

int main()
{
	int n;
	cout<<"Enter a number: ";
	cin>>n;
	cout<<"In increasing order"<<endl;
	printInc(n);
	cout<<"\nIn decreasing order"<<endl;
	printDec(n);
	return 0;
}