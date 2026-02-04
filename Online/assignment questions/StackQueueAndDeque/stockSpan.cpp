// STOCK SPAN
// The stock span problem is a financial problem where we have a series of N daily price quotes for a stock and we need to calculate span of stock’s price for all N days. You are given an array of length N, where ith element of array denotes the price of a stock on ith. Find the span of stock's price on ith day, for every 1<=i<=N.
// A span of a stock's price on a given day, i, is the maximum number of consecutive days before the (i+1)th day, for which stock's price on these days is less than or equal to that on the ith day.

// Input Format:
// Enter the size of the array N and add N more numbers and store in the array.

// Constraints:
// None

// Output Format
// Display the array containing stock span values.

// Sample Input
// 5
// 30
// 35
// 40
// 38
// 35
// Sample Output
// 1 2 3 1 1 END


#include<iostream>
#include<stack>
using namespace std;

void findStockSpan(int arr[],int sol[],int n)
{
    stack<int> cont;
    sol[0]=1;
    cont.push(0);
    for(int i=1;i<n;i++)
    {
        if(arr[i]<arr[cont.top()])
        {
            sol[i]=1;
        }
        else
        {
            while(!cont.empty() && arr[i]>=arr[cont.top()])
            {
                sol[i]+=sol[cont.top()];
                cont.pop();
            }
            sol[i]+=1;
        }
        cont.push(i);
    }
}

// void findStockSpan1(int arr[],int sol[],int n)
// {
//     sol[0]=1;
//     for(int i=1;i<n;i++)
//     {
//         if(arr[i]>arr[i-1])
//         {
//             sol[i]=sol[i-1]+1;
//         }
//         else
//         {
//             sol[i]=1;
//         }
//     }
// }

int main() {
    int n;
    cin>>n;
    int arr[1000];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int sol[1000];
    findStockSpan(arr,sol,n);
    for(int i=0;i<n;i++)
    {
        cout<<sol[i]<<" ";
    }
    cout<<"END"<<endl;
	return 0;
}