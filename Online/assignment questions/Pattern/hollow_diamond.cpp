// HOLLOW DIAMOND PATTERN(PATTERN 6)
// Take N (number of rows), print the following pattern (for N = 5).

//      * * * * *
//      * *   * *
//      *       *
//      * *   * *
//      * * * * *
// Input Format:
// Constraints:
// 0 < N < 10 (where N is an odd number)

// Output Format
// Sample Input
// 5
// Sample Output
// *   *   *   *   *   *          
// *   *           *   *
// *                   *
// *   *           *   *
// *   *   *   *   *   *


#include<iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int row=1;
    int nst=n/2+1;
    int nsp=-1;
    while(row<=n)
    {
        int cst=1;
        int csp=1;
        while(cst<=nst)
        {
            cout<<"* ";
            cst++;
        }
        while(csp<=nsp)
        {
            cout<<"  ";
            csp++;
        }
        cst=1;
        if(row==1 || row==n)
            cst=2;
        while(cst<=nst)
        {
            cout<<"* ";
            cst++;
        }
        cout<<endl;
        if(row<=n/2)
        {
            nst--;
            nsp+=2;
        }
        else
        {
            nst++;
            nsp-=2;
        }
        row++;
    }
	return 0;
}