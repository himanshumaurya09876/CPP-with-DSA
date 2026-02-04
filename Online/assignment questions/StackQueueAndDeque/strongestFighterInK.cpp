// STRONGEST FIGHTER
// There is a group of MMA fighters standing together in a line. Given the value of their strengths, find the strength of the strongest fighter in continuous sub-groups of size k.

// Input Format:
// First line contains an integer N, the number of fighters Followed by N integers where i'th integer denotes the strength of i'th fighter. Next line contains the size of sub-group k

// Constraints:
// 1<=N<=10^5 1<=k<=N

// Output Format
// Space separated integers in a single line denoting strength of strongest fighters in the groups.

// Sample Input
// 5
// 1 3 1 4 5
// 3
// Sample Output
// 3 4 5


#include<iostream>
#include<queue>
using namespace std;

void printStrongestInK(int arr[],int n,int k)
{
    deque<int> dq;
    for(int i=0;i<n;i++)
    {
        if(i<k)
        {
            while(!dq.empty() && arr[i]>arr[dq.back()])
            {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        else
        {
            cout<<arr[dq.front()]<<" ";
            if(dq.front()<=i-k)
            {
                dq.pop_front();
            }
            while(!dq.empty() && arr[i]>arr[dq.back()])
            {
                dq.pop_back();
            }
            dq.push_back(i);
        }
    }
    cout<<arr[dq.front()]<<" ";
}

int main() {
    int n,arr[100000],k;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cin>>k;
    printStrongestInK(arr,n,k);
	return 0;
}