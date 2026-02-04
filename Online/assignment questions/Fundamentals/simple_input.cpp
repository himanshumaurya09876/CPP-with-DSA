#include<iostream>
using namespace std;
int main() {
	int sum=0;
	int n;
	cin>>n;
	sum=sum+n;
	while(sum>=0)
	{
		cout<<n<<endl;
		cin>>n;
		sum=sum+n;
	}
	return 0;
}