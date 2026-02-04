// MODULAR EXPONENTIATION
// Given three numbers a,b,c. Calculate (a^b)mod c.

// Input Format:
// Single line containing three integers a,b,c separated by space.

// Constraints:
// 1<=a,b,c<=100000

// Output Format
// Print (a^b)mod c.

// Sample Input
// 2 2 3
// Sample Output
// 1


#include<iostream>
using namespace std;
int findAns(int a,int b,int c)
{
    if(b==2)
    {
        return ((a%c)*(a%c))%c;
    }
    return ((a%c)*(findAns(a,b-1,c)%c))%c;
}
int main() {
    int a,b,c;
    cin>>a>>b>>c;
    cout<<findAns(a,b,c)<<endl;
	return 0;
}

// #include<iostream>
// using namespace std;

// int main() {
//     long long int a,b,c;
//     cin>>a>>b>>c;
//     long long int res=1;
//     for(long long int i=1;i<=b;i++)
//     {
//         res=((res%c)*(a%c))%c;
//     }
//     cout<<res<<endl;
// 	return 0;
// }