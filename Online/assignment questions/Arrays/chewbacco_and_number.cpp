// CHEWBACCA AND NUMBER
// Luke Skywalker gave Chewbacca an integer number x. Chewbacca isn't good at numbers but he loves inverting digits in them. Inverting digit t means replacing it with digit 9 - t.

// Help Chewbacca to transform the initial number x to the minimum possible positive number by inverting some (possibly, zero) digits. The decimal representation of the final number shouldn't start with a zero.

// Input Format:
// The first line contains a single integer x (1 ≤ x ≤ 10^18) — the number that Luke Skywalker gave to Chewbacca.

// Constraints:
// x <= 100000000000000000

// Output Format
// Print the minimum possible positive number that Chewbacca can obtain after inverting some digits. The number shouldn't contain leading zeroes.

// Sample Input
// 4545
// Sample Output
// 4444

#include<bits/stdc++.h>
using namespace std;
int main() {
	long long int x,y=0;
	int l=0,d;
	cin>>x;
	while(x>0)
	{
		d=x%10;
		if(d>=5)
			d=9-d;
		y=d*pow(10,l)+y;
		l++;
		x=x/10;
	}
	if(d==0)
	{
		y=9*pow(10,l-1)+y;
	}
	cout<<y;
	return 0;
}
