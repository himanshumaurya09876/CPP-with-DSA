// TRICKY PERMUTATIONS
// Given a string containing duplicates, print all its distinct permutations such that there are no duplicate permutations and all permutations are printed in a lexicographic order.

// NOTE: DO NOT USE MAP OR SET.

// Input Format:
// The first and only line of the test case contains the input string.

// Constraints:
// Length of the string <= 8

// Output Format
// Print all the distinct permutations in a lexicographic order such that each permutation is in a new line. Note that there should not be any duplicate permutations.

// Sample Input
// ABA
// Sample Output
// AAB
// ABA
// BAA

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

void printAllUniquePermutations(string in,string out="")
{
	int l=in.length();
	if(l==0)
	{
		cout<<out<<endl;
		return;
	}
	printAllUniquePermutations(in.substr(1),out+in[0]);
	for(int i=1;i<l;i++)
	{
		if(in[i]!=in[i-1])
		{
			printAllUniquePermutations(in.substr(0,i)+in.substr(i+1),out+in[i]);
		}
	}
}

int main(int argc, char const *argv[])
{
	string str;
	cin>>str;
	int l=str.length();
	sort(str.begin(),str.end());
	printAllUniquePermutations(str);
	return 0;
}