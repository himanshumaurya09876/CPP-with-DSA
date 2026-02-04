// HISTOGRAM
// Find the largest rectangular area possible in a given histogram where the largest rectangle can be made of a number of contiguous bars.


// Input Format:
// First line contains a single integer N, denoting the number of bars in th histogram. Next line contains N integers, ith of which, denotes the height of ith bar in the histogram.

// Constraints:
// 1<=N<=10^6 Height of each bar in histogram <= 10^9

// Output Format
// Output a single integer denoting the area of the required rectangle.

// Sample Input
// 5
// 1 2 3 4 5
// Sample Output
// 9


// #include<iostream>
// #include<stack>
// #define ll long long int
// using namespace std;

// ll maxArea(ll arr[],ll n)
// {
//     stack<ll> st;
//     ll maxArea=0;
//     for(ll i=0;i<n;i++)
//     {
//         if(st.empty() || arr[i]>=arr[st.top()])
//         {
//             st.push(i);
//         }
//         else
//         {
//             while(!st.empty() && arr[i]<arr[st.top()])
//             {
//                 ll num=arr[st.top()];
//                 st.pop();
//                 ll left=0;
//                 if(!st.empty())
//                 {
//                     left=st.top();
//                 }
//                 ll right=i-1;
//                 ll area=num*(right-left);
//                 if(maxArea<area)
//                 {
//                     maxArea=area;
//                 }
//             }
//             st.push(i);
//         }
//     }
//     while(!st.empty())
//     {
//         ll num=arr[st.top()];
//         st.pop();
//         ll left=0;
//         if(!st.empty())
//         {
//             left=st.top();
//         }
//         ll right=n-1;
//         ll area=num*(right-left);
//         if(maxArea<area)
//         {
//             maxArea=area;
//         }
//     }
//     return maxArea;
// }

// int main() {
//     ll n,arr[10000];
//     cin>>n;
//     for(ll i=0;i<n;i++)
//     {
//         cin>>arr[i];
//     }
//     cout<<maxArea(arr,n)<<endl;
//     return 0;
// }



#include<iostream>
#include<stack>
using namespace std;
typedef long long int ll;
ll largest_area(long arr[],ll n)
{
    stack <ll> s;
    ll max_area=0;
    ll tp,top_area;
    ll i=0;
    while(i<n)
    {
        if(s.empty()||arr[s.top()] <=arr[i])
        {
            s.push(i++);
        }
        else
        {
            tp=s.top();
            s.pop();
            top_area = arr[tp] * (s.empty() ? i :  i - s.top() - 1); 
            if (max_area < top_area) 
                max_area =top_area; 
        } 
    }
    while (s.empty() == false) 
    { 
        tp = s.top(); 
        s.pop(); 
        top_area = arr[tp] * (s.empty() ? i :  i - s.top() - 1); 
  
        if (max_area < top_area) 
            max_area = top_area; 
    } 
  
    return max_area;  
}
int main()
{
    long arr[1000000];
    ll n;
    cin>>n;
    for(ll i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<largest_area(arr,n);
    return 0;
}