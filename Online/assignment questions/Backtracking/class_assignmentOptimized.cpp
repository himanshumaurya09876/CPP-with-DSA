// CLASS ASSIGNMENT
// In a mathematics class, Teacher ask Alice to find the number of all n digit distinct integers which is formed by the two distinct digits ai and bi but there is a rule to form n digit integer.

// Rule: She has to form n digit integer by using two digits ai and bi without consecutive bi.

// Alice is very weak in maths section. Help her to find the number of such n digit integers.

// Input Format:
// The first line contains T, the number of test cases. Further T lines contains the value n which is the number of digit in the integer.

// Constraints:
// 1<=T<=40 1<=n<44

// Output Format
// For each test case print the number of such n digit integer.

// Sample Input
// 3
// 1
// 2
// 3
// Sample Output
// #1 : 2
// #2 : 3
// #3 : 5

//simply print nth fibonacci number starting from 2
#include<iostream>
using namespace std;

int noOfInt(int n)
{
	int a=2,b=3,res=a+b;;
	while(n>1)
	{
		a=b;
		b=res;
		res=a+b;
		n--;
	}
	return a;
}

int main() {
	int t;
	cin>>t;
	int i=1;
	while(i<=t)
	{
		int n;
		cin>>n;
		cout<<"#"<<n<<" : "<<noOfInt(n)<<endl;
		i++;
	}
	return 0;
}

// #include<iostream>
// #define ll long long
// using namespace std;

// ll noOfInt(ll n)
// {
// 	ll a=2,b=3,res=a+b;;
// 	while(n>1)
// 	{
// 		a=b;
// 		b=res;
// 		res=a+b;
// 		n--;
// 	}
// 	return a;
// }

// int main() {
// 	ll t;
// 	ll i=1;
// 	cin>>t;
// 	while(i<=t)
// 	{
// 		ll n;
// 		cin>>n;
// 		cout<<"#"<<i<<" : "<<noOfInt(n)<<endl;
// 		i++;
// 	}
// 	return 0;
// }