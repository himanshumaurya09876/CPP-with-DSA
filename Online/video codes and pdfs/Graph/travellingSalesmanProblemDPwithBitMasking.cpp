// this problem can be solved in O(n!) -> bruteforce
// with little optimization it can be reduced to O((n-1)!)
// using DP with bitmasking complexity can be reduced to O((2^n)*n)


// #include <iostream>
// using namespace std;

// #define INT_MAX 999999

// int n=4;
// int dp[16][4];

// // Adj Matrix which defines the graph
// int dist[10][10] = {
//         {0,20,42,25},
//         {20,0,30,34},
//         {42,30,0,10},
//         {25,34,10,0}
// };

// //If all cities have been visited
// int VISITED_ALL = (1<<n) - 1;

// int tsp(int mask,int pos){
    
//     if(mask==VISITED_ALL){
//         return dist[pos][0];
//     }
//     //Lookup 
//     if(dp[mask][pos]!=-1){
//         return dp[mask][pos];
//     }
    
//     int ans = INT_MAX;
//     //Try to goto an unvisited city
//     for(int city=0;city<n;city++){
        
//         if((mask&(1<<city))==0){
            
//             int newAns = dist[pos][city] + tsp( mask|(1<<city),city);
//             ans = min(ans,newAns);
            
//         }
        
        
//     }
    
//     return dp[mask][pos] = ans;
    
// }

// int main() {
    
//     for(int i=0;i<(1<<n);i++){
//         for(int j=0;j<n;j++){
//             dp[i][j] = -1;
//         }
//     }
    
//     cout<<"Min weight hamiltonian path costs "<<tsp(1,0)<<endl;
//     return 0;
// }


#include <iostream>
#define inf 99999
using namespace std;
int count;
int n=4;
int graph[4][4]={{0,20,42,25},
                 {20,0,30,34},
                 {42,30,0,10},
                 {25,34,10,0}};

int visited_all=(1<<n)-1;

int minTravelDist(int pos=0,int mask=1)// here we started from 1 not zero
{
    count++;
    if(mask==visited_all)
    {
        return graph[pos][0];
    }

    int ans=inf;
    for(int i=0;i<n;i++)
    {
        if((mask&(1<<i))==0)
        {
            ans=min(ans,graph[pos][i]+minTravelDist(i,mask|(1<<i)));
        }
    }

    return ans;
}

int dp[4][16];

int minTravelDistTD(int pos=0,int mask=1)// here we started from 1 not zero
{
    count++;
    if(mask==visited_all)
    {
        return graph[pos][0];
    }

    if(dp[pos][mask]!=-1)
    {
        return dp[pos][mask];
    }

    int ans=inf;
    for(int i=0;i<n;i++)
    {
        if((mask&(1<<i))==0)
        {
            ans=min(ans,graph[pos][i]+minTravelDistTD(i,mask|(1<<i)));
        }
    }

     dp[pos][mask]=ans;
     return ans;
}

int main(int argc, char const *argv[])
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<16;j++)
        {
            dp[i][j]=-1;
        }
    }
    count=0;
    cout<<minTravelDistTD()<<" "<<count<<endl;
    count=0;
    cout<<minTravelDist()<<" "<<count<<endl;
    return 0;
}