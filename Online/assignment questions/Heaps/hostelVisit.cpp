// HOSTEL VISIT
// Dean of MAIT is going to visit Hostels of MAIT. As you know that he is a very busy person so he decided to visit only first "K" nearest Hostels. Hostels are situated in 2D plane. You are given the coordinates of hostels and you have to answer the Rocket distance of Kth nearest hostel from origin ( Dean's place ) .

// Input Format:
// First line of input contains Q Total no. of queries and K There are two types of queries:

// first type : 1 x y For query of 1st type, you came to know about the co-ordinates ( x , y ) of newly constructed hostel. second type : 2 For query of 2nd type, you have to output the Rocket distance of Kth nearest hostel till now.

// The Dean will always stay at his place ( origin ). It is gauranted that there will be atleast k queries of type 1 before first query of type 2.

// Rocket distance between two points ( x2 , y2 ) and ( x1 , y1 ) is defined as (x2 - x1)2 + (y2 - y1)2

// Constraints:
// 1 < = k < = Q < = 10^5 -10^6 < = x , y < = 10^6

// Output Format
// For each query of type 2 output the Rocket distance of Kth nearest hostel from Origin.

// Sample Input
// 9 3
// 1 10 10
// 1 9 9
// 1 -8 -8
// 2
// 1 7 7
// 2
// 1 6 6 
// 1 5 5
// 2
// Sample Output
// 200
// 162
// 98

// #include <iostream>
// #include <queue>
// using namespace std;

// int X=0,Y=0;

// class coordinate
// {
// public:
// 	int x;
// 	int y;
// 	int rocketDist;

// 	coordinate(int x,int y)
// 	{
// 		this->x=x;
// 		this->y=y;
// 		rocketDist=(x-X)*(x-X)+(y-Y)*(y-Y);
// 	}
// };

// class compare
// {
// public:
// 	bool operator()(coordinate a,coordinate b)
// 	{
// 		return a.rocketDist>b.rocketDist;
// 	}
// };

// void printKthNearest(priority_queue<coordinate,vector<coordinate>,compare> pq,int k)
// {
// 	while(k>1)
// 	{
// 		pq.pop();
// 		k--;
// 	}
// 	cout<<pq.top().rocketDist<<endl;
// }

// int main(int argc, char const *argv[])
// {
// 	int q,k;
// 	priority_queue<coordinate,vector<coordinate>,compare> pq;
// 	cin>>q>>k;
// 	while(q>0)
// 	{
// 		int t;
// 		cin>>t;
// 		if(t==1)
// 		{
// 			int x,y;
// 			cin>>x>>y;
// 			coordinate c(x,y);
// 			pq.push(c);
// 		}
// 		else
// 		{
// 			printKthNearest(pq,k);
// 		}
// 		q--;
// 	}
// 	return 0;
// }






#include <iostream>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;

ll X=0,Y=0;

class coordinate
{
public:
	ll x;
	ll y;
	ll rocketDist;

	coordinate(ll x,ll y)
	{
		this->x=x;
		this->y=y;
		rocketDist=(x-X)*(x-X)+(y-Y)*(y-Y);
	}
};

class compare
{
public:
	bool operator()(coordinate a,coordinate b)
	{
		return a.rocketDist<b.rocketDist;
	}
};

int main()
{
	ll q,k;
	priority_queue<coordinate,vector<coordinate>,compare> pq;
	cin>>q>>k;
	while(q>0)
	{
		ll t;
		cin>>t;
		if(t==1)
		{
			ll x,y;
			cin>>x>>y;
			coordinate c(x,y);
			if(k>0)
			{
				pq.push(c);
				k--;
			}
			else
			{
				if(c.rocketDist<pq.top().rocketDist)
				{
					pq.pop();
					pq.push(c);
				}
			}
		}
		else
		{
			cout<<pq.top().rocketDist<<endl;
		}
		q--;
	}
	return 0;
}