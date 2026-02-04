// PLAYING WITH CARDS (IN STACK)
// You are at a casino. There are N stacked cards on pile . Each card has a number written on it. Then there will be Q iterations. In ith iteration, you start picking up the cards in Ai-1th pile from the top one by one and check whether the number written on the card is divisible by the ith prime number. If the number is divisible, you stack that card on pile Bi. Otherwise, you stack that card on pile Ai. After Q iterations, cards can only be on pile B1, B2, B3, . . . BQ, AQ . Output numbers on these cards from top to bottom of each piles in order of B1, B2, B3, . . . BQ, AQ .

// Input Format:
// First line contains N and Q. The next line contains N space separated integers representing the initial pile of cards i.e., A0. The leftmost value represents the bottom plate of the pile.

// Constraints:
// N < 10^5

// Output Format
// Output N lines, each line containing the number written on the card.

// Sample Input
// 5 1
// 3 4 7 6 5
// Sample Output
// 4
// 6
// 3
// 7
// 5

#include <iostream>
#include <stack>
#include <vector>
#define ll long long int
using namespace std;

ll primeNoList[100005];

void buildPrimeNoList()
{
	bool primeSieve[1000005];

	for(ll i=0;i<1000005;i++)
	{
		if(i%2)
		{
			primeSieve[i]=1;
		}
		else
		{
			primeSieve[i]=0;
		}
	}

	primeSieve[1]=0;
	primeSieve[2]=1;

	for(ll i=3;i<1000005;i+=2)
	{
		for(ll j=i*i;j<1000005;j+=2*i)
		{
			primeSieve[j]=0;
		}
	}

	fill(primeNoList,primeNoList+100005,-1);
	ll j=0;
	for(ll i=0;i<1000005;i++)
	{
		if(primeSieve[i])
		{
			primeNoList[j++]=i;
		}
	}

	// //print primeNoList 
	// for(ll i=0;i<100005;i++)
	// {
	// 	cout<<primeNoList[i]<<" ";
	// }
}

int main()
{
	buildPrimeNoList();
	ll n,q,i;
	cin>>n>>q;
	vector<stack<ll> > B;
	
	stack<ll> A[2];
	for(i=0;i<n;i++)
	{
		ll num;
		cin>>num;
		A[0].push(num);
	}
	
	i=0;
	int j=1;
	while(i<q)
	{
		stack<ll> b;
		while(!A[1-j].empty())
		{
			ll num=A[1-j].top();
			if(num%primeNoList[i]==0)
			{
				b.push(num);
			}
			else
			{
				A[j].push(num);
			}
			A[1-j].pop();
		}

		B.push_back(b);
		i++;
		j=1-j;
	}

	for(auto it:B)
	{
		while(!it.empty())
		{
			cout<<it.top()<<endl;
			it.pop();
		}
	}

	while(!A[1-j].empty())
	{
		cout<<A[1-j].top()<<endl;
		A[1-j].pop();
	}
	return 0;
}