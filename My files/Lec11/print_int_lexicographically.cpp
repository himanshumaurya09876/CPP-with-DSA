//print integers up to n lexicographically

#include <iostream>

using namespace std;

void printInts(int n,int sol=0)
{
	if(sol>n)
		return;
	int i=0,temp;
	if(sol==0)
		i++;
	cout<<sol<<endl;
	for(i;i<10;i++)
	{
		temp=sol;
		temp=temp*10+i;
		printInts(n,temp);
	}
}

int main()
{
	int n;
	cin>>n;
	printInts(n);
}