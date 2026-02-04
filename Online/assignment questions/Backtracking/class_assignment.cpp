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

#include<iostream>
using namespace std;
int countInt(int n,string out="")
{
    if(n==0)
    {
        return 1;
    }
    int res1=countInt(n-1,'a'+out);
    int res2=0;
    if(out!="")
    {
        if(out[0]!='b')
        {
            res2=countInt(n-1,'b'+out);
        }
    }
    else
    {
        res2=countInt(n-1,'b'+out);
    }
    return res1+res2;
}
int main() {
    int t,i=1;
    cin>>t;
    while(i<=t)
    {
        int n;
        cin>>n;
        cout<<"#"<<i<<" : "<<countInt(n)<<endl;
        i++;
    }
	return 0;
}