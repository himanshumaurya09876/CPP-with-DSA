// IMPORTANCE OF TIME
// There are N processes to be completed. All the processes have a unique number assigned to them from 1 to N.

// Now, we are given two things:

// 1)The calling order in which all the processes are called.
// 2)The ideal order in which all the processes should have been executed.

// Executing a process takes 1 unit of time. Changing the position takes 1 unit of time.

// We have to find out the unit of time required to complete all the process such that a process is executed from the ideal order only when it exists at the same index in the calling order. We can push the first term from the calling order to the last thus rotating the order.

// Input Format:
// A single number N

// Constraints:
// N < 100

// Output Format
// The total time required

// Sample Input
// 5
// 5 4 2 3 1
// 5 2 1 4 3
// Sample Output
// 7

#include<iostream>
#include<queue>
using namespace std;

int totalTime(int arr1[],int arr2[],int n)
{
    int total=0;
    deque<int> dq;
    queue<int> q;
    for(int i=0;i<n;i++)
    {
        dq.push_back(arr1[i]);
        q.push(arr2[i]);
    }
    while(!q.empty())
    {
        if(q.front()==dq.front())
        {
            total++;
            q.pop();
            dq.pop_front();
        }
        else
        {
            while(dq.front()!=q.front())
            {
                int num=dq.front();
                dq.pop_front();
                dq.push_back(num);
                total++;
            }
        }
    }
    return total;
}

int main() {
    int n,arr1[100],arr2[100];
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr1[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>arr2[i];
    }
    cout<<totalTime(arr1,arr2,n)<<endl;
	return 0;
}