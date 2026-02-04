// MAXIMUM XOR SUBARRAY
// Given an array of n integers, find subarray whose xor is maximum. A subarray is a contiguous part of array.

// Input Format:
// First line contains single integer n (1<=n<=1000). Next line contains n space separated integers

// Constraints:
// 1 <= n <= 1000 1 <= A[i] <=1000

// Output Format
// Print xor of the subarray whose xor of all elements in subarray is maximum over all subarrays.

// Sample Input
// 4
// 1 2 3 4
// Sample Output
// 7

#include <iostream>
using namespace std;

// //bruteforce approach
// int maxXORvalue(int arr[],int n)
// {
// 	int *cumXOR=new int[n];
// 	cumXOR[0]=arr[0];
// 	for(int i=1;i<n;i++)
// 	{
// 		cumXOR[i]=arr[i]^cumXOR[i-1];
// 	}

// 	int maxXOR=cumXOR[0];
// 	for(int i=1;i<n;i++)
// 	{
// 		for(int j=i;j<n;j++)
// 		{
// 			maxXOR=max(maxXOR,cumXOR[j]^cumXOR[i-1]);
// 		}
// 	}

// 	return maxXOR;
// }

//using trie it becomes most optimized
//in cumXOR array if we will take any element at i then we will try to find another jth element from 0 to i-1 and try to maximise XOR between this 
//jth and ith element and also we will take XOR of ith with 0 after that we will pick maximum res
//we will try all combinations of i and j (between 0 and i-1)(also 0) then select one with maximum res
//look at this code of using trie it is putting first zero in the trie after that each entry of cumXOR array and simultaneously finding the best
//match for each entry to maximise XOR res ie if bits in entry is 0 then it search for 1 and vice versa....

class Node
{
public:
	int value;
	Node* left;
	Node* right;

	Node()
	{
		value=0;
		left=NULL;
		right=NULL;
	}
};

class Trie
{
private:
	Node* root;
public:
	Trie()
	{
		root=new Node;
	}

	void insert(int n)
	{
		Node* curr=root;
		for(int i=31;i>=0;i--)
		{
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
		curr->value=n;
	}

	int xorWithBestMatch(int x)
	{
		Node* curr=root;
		for(int i=31;i>=0;i--)
		{
			bool bit=x&(1<<i);
			if(bit==0)
			{
				if(curr->right!=NULL)
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
				if(curr->left!=NULL)
				{
					curr=curr->left;
				}
				else
				{
					curr=curr->right;
				}
			}
		}
		return x^curr->value;
	}
};

int findMaxXOR(int arr[],int n)
{
	int prevXOR=0;
	int maxXOR=INT_MIN;
	Trie t;
	t.insert(0);
	for(int i=0;i<n;i++)
	{
		prevXOR^=arr[i];
		t.insert(prevXOR);
		maxXOR=max(maxXOR,t.xorWithBestMatch(prevXOR));
		// cout<<maxXOR<<endl;
	}

	return maxXOR;
}

int main()
{
	int n;
	cin>>n;
	int *arr=new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}

	// cout<<maxXORvalue(arr,n)<<endl;
	cout<<findMaxXOR(arr,n)<<endl;
	return 0;
}