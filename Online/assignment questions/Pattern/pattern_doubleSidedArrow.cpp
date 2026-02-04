// PATTERN DOUBLESIDEDARROW
// Take N as input. For a value of N=7, we wish to draw the following pattern :

//                             1 
//                         2 1   1 2 
//                     3 2 1       1 2 3 
//                 4 3 2 1           1 2 3 4 
//                     3 2 1       1 2 3 
//                         2 1   1 2 
//                             1 
// Input Format:
// Take N as input.

// Constraints:
// N is odd number.

// Output Format
// Pattern should be printed with a space between every two values.

// Sample Input
// 7
// Sample Output
//             1 
//         2 1   1 2 
//     3 2 1       1 2 3 
// 4 3 2 1           1 2 3 4 
//     3 2 1       1 2 3 
//         2 1   1 2 
//             1 


#include<iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    n=n/2+1;
    int row=1;
    int nst=1;
    int nsp1=2*(n-1);
    int nsp2=-1;
    while(row<=2*n-1)
    {
        int csp=1;
        while(csp<=nsp1)
        {
            cout<<"  ";
            csp++;
        }
        int cst=1;
        while(cst<=nst)
        {
            cout<<nst-cst+1<<" ";
            cst++;
        }
        csp=1;
        while(csp<=nsp2)
        {
            cout<<"  ";
            csp++;
        }
        cst=1;
        while(cst<=nst)
        {
            if(row!=1 && row!=2*n-1)
                cout<<cst<<" ";
            cst++;
        }
        cout<<endl;
        if(row<n)
        {
            nsp1-=2;
            nsp2+=2;
            nst++;
        }
        else
        {
            nsp1+=2;
            nsp2-=2;
            nst--;
        }
        row++;
    }
	return 0;
}