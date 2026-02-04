//Euclid's algorithm
// GCD
// Take the following as input.

// A number (N1)
// A number (N2)
// Write a function which returns the GCD of N1 and N2. Print the value returned.

// Input Format:
// Constraints:
// 0 < N1 < 1000000000 0 < N2 < 1000000000

// Output Format
// Sample Input
// 16 
// 24
// Sample Output
// 8

#include<iostream>
using namespace std;
int gcd(int a,int b)
{
	if(b==0)
	{
		return a;
	}
	return gcd(b,a%b);
}
int main() {
	int a,b;
	cin>>a>>b;
	cout<<gcd(a,b)<<endl;
	return 0;
}