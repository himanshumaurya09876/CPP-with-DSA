// RANGE XOR
// You are given an array and Q queries of two types. Type 0: Given a number x , insert the number at the last of the array. Type 1: Given a number X and two integers L, R, Find a number Y in the range L, R to maximize X ^ Y

// Input Format:
// First line of the test case will be the number of queries Q . Then on next Q subsequent lines you will be given a query either of type 0 or type 1. Query of type 0 is of the form : 0 X, where X is the integer to be inserted . Query of type 1 is of the form : 1 L R X

// Constraints:
// 0 <= element of array <= 10^9 1 <= N <= 10^5

// Output Format
// For each query of type 1 output the desired value.

// Sample Input
// 5
// 0 3 
// 0 5
// 0 10 
// 0 6 
// 1 1 4 6
// Sample Output
// 10

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// //bruteforce approach
// int findMaxXOR(vector<int> &v,int l,int r,int x)
// {
// 	int maxXOR=INT_MIN;
// 	int num=-1;
// 	for(int i=l-1;i<=r-1;i++)
// 	{
// 		int currXOR=x^v[i];
// 		if(maxXOR<currXOR)
// 		{
// 			maxXOR=currXOR;
// 			num=v[i];
// 			// cout<<maxXOR<<" "<<num<<endl;
// 		}
// 	}
// 	return num;
// }

class Node
{
public:
	int value;
	Node* left;
	Node* right;
	vector<int> *idxList;

	Node()
	{
		value=0;
		left=NULL;
		right=NULL;
		idxList=new vector<int>;
	}
};

bool isPresent(Node *obj,int l,int r)
{
	vector<int> *v=obj->idxList;

	//this search is in O(n)
	// for(auto it:*v)
	// {
	// 	if(it>=l and it<=r)
	// 	{
	// 		return true;
	// 	}
	// }


	//this search is in O(logn)
	//because during insertion idxList will always be sorted
	vector<int> ::iterator it=upper_bound(v->begin(),v->end(),l-1);
	if(it!=v->end() and *it<=r)
	{
		return true;
	}
	

	return false;
}

class Trie
{
private:
	Node* root;
public:
	Trie()
	{
		root=new Node;
	}

	void insert(int n,int idx)
	{
		Node* curr=root;
		for(int i=31;i>=0;i--)
		{
			curr->idxList->push_back(idx);
			bool bit=n&(1<<i);
			if(bit==0)
			{
				if(curr->left==NULL)
				{
					curr->left=new Node;
				}
				curr=curr->left;
			}
			else
			{
				if(curr->right==NULL)
				{
					curr->right=new Node;
				}
				curr=curr->right;
			}
		}
		curr->idxList->push_back(idx);
		curr->value=n;
	}

	int xorWithBestMatch(int l,int r,int x)
	{
		Node* curr=root;
		for(int i=31;i>=0;i--)
		{
			bool bit=x&(1<<i);
			if(bit==0)
			{
				if(curr->right!=NULL && isPresent(curr->right,l,r))
				{
					curr=curr->right;
				}
				else
				{
					curr=curr->left;
				}
			}
			else
			{
				if(curr->left!=NULL && isPresent(curr->left,l,r))
				{
					curr=curr->left;
				}
				else
				{
					curr=curr->right;
				}
			}
		}
		return curr->value;
	}
};

int main(int argc, char const *argv[])
{
	int q,idx=1;
	Trie t;
	cin>>q;
	while(q>0)
	{
		bool type;
		cin>>type;
		if(type)
		{
			int l,r,x;
			cin>>l>>r>>x;
			cout<<t.xorWithBestMatch(l,r,x)<<endl;
		}
		else
		{
			int x;
			cin>>x;
			t.insert(x,idx);
			idx++;
		}
		q--;
	}
	return 0;
}

