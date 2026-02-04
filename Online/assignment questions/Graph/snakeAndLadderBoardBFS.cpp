// SNAKE AND LADDERS BOARD (BFS)
// Given a snake and ladder board, find the minimum number of dice throws required to reach the destination or last cell from source or 1st cell. The player has total control over outcome of dice throw and wants to find out minimum number of throws required to reach last cell.

// Input Format:
// First line contains integer t as number of test cases. Each test case contains following input. First line contains three integers n, l, s which represents the number of cell of board, number of ladders and number of snakes. Following l lines contains the description of ladders and next s lines contains description of snakes.

// Image

// Constraints:
// 1 < t < 20 1< n,l,s < 50

// Output Format
// For each test case you have to print the number which is equal to the minimum number of dice throws to reach the last cell.

// Sample Input
// 1
// 30 4 4
// 3 22
// 5 8
// 11 26
// 20 29
// 17 4
// 19 7
// 21 9
// 27 1
// Sample Output
// 3

#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

int sssp(int jumps[],int n)
{
	int src=1;
	queue<int> q;
	unordered_map<int,bool> isVisited;
	unordered_map<int,int> dist;
	unordered_map<int,int> parent;
	for(int i=1;i<=n;i++)
	{
		dist[i]=INT_MAX;
		isVisited[i]=false;
	}
	isVisited[src]=true;
	dist[src]=0;
	q.push(src);
	while(!q.empty())
	{
		int entry=q.front();
		q.pop();
		for(int it=entry+1;it<=entry+6 && it<=n;it++)
		{
			if(!isVisited[it+jumps[it]])
			{
				q.push(it+jumps[it]);
				isVisited[it+jumps[it]]=true;
				dist[it+jumps[it]]=dist[entry]+1;
				parent[it+jumps[it]]=entry;
			}
		}
	}
	// cout<<endl;

	// for(auto it:dist)
	// {
	// 	cout<<"Distance of "<<it.first<<" from "<<src<<" is "<<it.second<<endl;
	// }

	// int temp=n;
	// while(temp!=src)
	// {
	// 	cout<<temp<<" <--  ";
	// 	temp=parent[temp];
	// }
	// cout<<src<<endl;
	return dist[n];
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t>0)
	{
		int n,l,s;
		cin>>n>>l>>s;
		int *jumps=new int[n+1];
		fill(jumps,jumps+n+1,0);
		for(int i=0;i<l+s;i++)
		{
			int u,v;
			cin>>u>>v;
			jumps[u]=v-u;
		}
		cout<<sssp(jumps,n)<<endl;
		t--;
	}
	return 0;
}