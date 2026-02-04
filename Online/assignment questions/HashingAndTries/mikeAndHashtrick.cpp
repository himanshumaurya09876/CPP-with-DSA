// MIKE AND HASHTRICK
// Mike loves mping. He decides to create his own mping technique, so he creates a Hash Function, given as :


// int* mp_array(int A[], int n)
// {
//     int* mp = new int[MAX]; //MAX is the maximum possible value of A[i]
//     for(int i=0;i<=MAX;i++) mp[i]=-1; //initialize mp to -1.
//     int count = 0;
//     for(int i=0;i<n;i++) // Loop through elements of array
//     {
//         if(mp[A[i]] == -1) // A[i] was not assigned any mp before
//         {
//             mp[A[i]] = count; // Assigning mp to A[i]
//             count++;
//             continue;
//         }
//         for(int j = 0;j<i;j++)
//         {
//             if(mp[A[j]] > mp[A[i]]) // All the mpes greater than previous mp of A[i] are decremented.
//                 mp[A[j]]--;
//         }
//         mp[A[i]] = count - 1; // Assigning a new mp to A[i]
//     }
//     return mp;
// }

// You are given an array A. You have to find the Mike's mpes for all the values that appears in this array.

// Input Format:
// First line contains a single integer n. Next line contains n integers, denoting the elements of array, A.

// Constraints:
// 1<=N<=10^5 1<=A[i]<=10^9

// Output Format
// Print k lines, where k is the number of distinct integers in A. ith line contains integer whose mp value is (i-1).

// Sample Input
// 4
// 1 2 1 3
// Sample Output
// 2
// 1
// 3

// #include <iostream>
// #include <algorithm>
// #include <unordered_map>
// #include <map>
// using namespace std;

// void mp_array(int A[], int n,unordered_map<int,int> &mp)
// {
//     int count = 0;
//     for(int i=0;i<n;i++)
//     {
//         if(mp.count(A[i])==0)
//         {
//             mp[A[i]] = count;
//             count++;
//             continue;
//         }
//         for(auto it:mp)
//         {
//             if(it.second > mp[A[i]])
//             {
//                 mp[it.first]--;
//             }
//         }
//         mp[A[i]] = count - 1;
//     }
// }

// int* mp_array1(int A[], int n)
// {
//     int MAX=INT_MIN;
//     for(int i=0;i<n;i++)
//     {
//         if(A[i]>MAX)
//         {
//             MAX=A[i];
//         }
//     }
//     int* mp = new int[MAX]; //MAX is the maximum possible value of A[i]
//     for(int i=0;i<=MAX;i++) mp[i]=-1; //initialize mp to -1.
//     int count = 0;
//     for(int i=0;i<n;i++) // Loop through elements of array
//     {
//         if(mp[A[i]] == -1) // A[i] was not assigned any mp before
//         {
//             mp[A[i]] = count; // Assigning mp to A[i]
//             count++;
//             continue;
//         }
//         for(int j = 0;j<i;j++)
//         {
//             if(mp[A[j]] > mp[A[i]]) // All the mpes greater than previous mp of A[i] are decremented.
//                 mp[A[j]]--;
//         }
//         mp[A[i]] = count - 1; // Assigning a new mp to A[i]
//     }
//     return mp;
// }

// int main()
// {
//     int n;
//     cin>>n;
//     int *arr=new int[n];
//     for(int i=0;i<n;i++)
//     {
//         cin>>arr[i];
//     }

//     // int *mp1=mp_array1(arr,n);
//     // for(int i=0;i<n;i++)
//     // {
//     //     if(mp1[i]!=-1)
//     //     {
//     //         cout<<i<<" ";
//     //     }
//     // }

//     cout<<endl<<"*******************************************************"<<endl;

//     unordered_map<int,int> hash;
//     mp_array(arr,n,hash);
//     map<int,int> mp;
//     for(auto it:hash)
//     {
//         // cout<<it.first<<" -> "<<it.second<<endl;
//         mp[it.second]=it.first;
//     }
//     for(auto it:mp)
//     {
//         cout<<it.second<<" ";
//     }
//     return 0;
// }






#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

unordered_map<int,int> mp;

bool compare(int a,int b)
{
    return mp[a]<mp[b];
}

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    vector<int> v;
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(mp.count(arr[i])==0)
        {
            v.push_back(arr[i]);
        }
        mp[arr[i]]=count;
        count++;
    }
    // for(auto it:mp)
    // {
    //     cout<<it.first<<" -> "<<it.second<<endl;
    // }
    // for(auto it:v)
    // {
    //     cout<<it<<" ";
    // }
    // cout<<endl;
    sort(v.begin(),v.end(),compare);
    for(auto it:v)
    {
        cout<<it<<" ";
    }
    return 0;
}
