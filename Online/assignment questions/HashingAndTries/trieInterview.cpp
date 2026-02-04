// TRIE INTERVIEW
// This placement season , Avinash is preparing for his upcoming interviews in multinational companies . He is trying to solve a problem which was previously asked in many companies. There is an array named arr. He is supposed to find the maximum value of (arr[a] ^ arr[a + 1] ^ arr[a + 2] …….. arr[b]) + (arr[c] ^ arr[c + 1] ^ arr[c + 2] …….. arr[d]) where 1 <= a <= b <= c <= d <= N , where N is the size of the array. Help him to find an optimal solution.

// Input Format:
// First line of the test case will be the length of array N . Then on the next line you will be given N space separated integers.

// Constraints:
// 0 <= element of array <= 10^9 1 <= N <= 10^5

// Output Format
// The output contains a single integer denoting the maximum value of expression

// Sample Input
// 4 
// 1 2 6 8
// Sample Output
// 17

// #include <iostream>
// using namespace std;

// class Node
// {
// public:
// 	int value;
// 	Node* left;
// 	Node* right;

// 	Node()
// 	{
// 		value=0;
// 		left=NULL;
// 		right=NULL;
// 	}
// };

// class Trie
// {
// private:
// 	Node* root;
// public:
// 	Trie()
// 	{
// 		root=new Node;
// 	}

// 	void insert(int n)
// 	{
// 		Node* curr=root;
// 		for(int i=31;i>=0;i--)
// 		{
// 			bool bit=n&(1<<i);
// 			if(bit==0)
// 			{
// 				if(curr->left==NULL)
// 				{
// 					curr->left=new Node;
// 				}
// 				curr=curr->left;
// 			}
// 			else
// 			{
// 				if(curr->right==NULL)
// 				{
// 					curr->right=new Node;
// 				}
// 				curr=curr->right;
// 			}
// 		}
// 		curr->value=n;
// 	}

// 	// void removeHelper(int n,int i,Node* curr)
// 	// {
// 	// 	if(i<0)
// 	// 	{
// 	// 		return;
// 	// 	}

// 	// 	bool bit=n&(1<<i);
// 	// 	if(bit==0)
// 	// 	{
// 	// 		removeHelper(n,i-1,curr->left);
// 	// 	}
// 	// 	else
// 	// 	{
// 	// 		removeHelper(n,i-1,curr->right);
// 	// 	}

// 	// 	delete curr;
// 	// }

// 	// void remove(int n)
// 	// {
// 	// 	bool bit=n&(1<<31);
// 	// 	if(bit==0)
// 	// 	{
// 	// 		removeHelper(n,30,root->left);
// 	// 	}
// 	// 	else
// 	// 	{
// 	// 		removeHelper(n,30,root->right);
// 	// 	}
// 	// }

// 	int xorWithBestMatch(int x)
// 	{
// 		Node* curr=root;
// 		for(int i=31;i>=0;i--)
// 		{
// 			bool bit=x&(1<<i);
// 			if(bit==0)
// 			{
// 				if(curr->right!=NULL)
// 				{
// 					curr=curr->right;
// 				}
// 				else
// 				{
// 					curr=curr->left;
// 				}
// 			}
// 			else
// 			{
// 				if(curr->left!=NULL)
// 				{
// 					curr=curr->left;
// 				}
// 				else
// 				{
// 					curr=curr->right;
// 				}
// 			}
// 		}
// 		return x^curr->value;
// 	}
// };

// int findMaxXOR(int arr[],int n)
// {
// 	int res=INT_MIN;
// 	Trie t1,t2;

// 	int prevXOR=0; 
// 	int maxXOR=INT_MIN;
// 	t2.insert(0);
// 	int *maxXORlistFromEnd=new int[n];
// 	for(int i=n-1;i>=0;i--)
// 	{
// 		prevXOR^=arr[i];
// 		t2.insert(prevXOR);
// 		maxXOR=max(maxXOR,t2.xorWithBestMatch(prevXOR));
// 		maxXORlistFromEnd[i]=maxXOR;
// 	}

// 	// for(int i=0;i<n;i++)
// 	// {
// 	// 	cout<<maxXORlistFromEnd[i]<<" ";
// 	// }
// 	// cout<<endl;

// 	prevXOR=0;
// 	maxXOR=INT_MIN;
// 	t1.insert(0);
// 	// int *maxXORlistFromStart=new int[n]; //since i am calculating my res in same loop using maxXOR so no need to fill this array
// 	for(int i=0;i<n-1;i++)
// 	{
// 		prevXOR^=arr[i];
// 		t1.insert(prevXOR);
// 		maxXOR=max(maxXOR,t1.xorWithBestMatch(prevXOR));
// 		// maxXORlistFromStart[i]=maxXOR;
// 		res=max(res,maxXOR+maxXORlistFromEnd[i+1]);
// 	}

// 	return res;
// }

// int main()
// {
// 	int n;
// 	cin>>n;
// 	int *arr=new int[n];
// 	for(int i=0;i<n;i++)
// 	{
// 		cin>>arr[i];
// 	}
// 	cout<<findMaxXOR(arr,n)<<endl;
// 	return 0;
// }






#include <iostream>
#include <climits>
using namespace std;

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
	int res=INT_MIN;
	Trie t1,t2;

	int prevXOR=0; 
	int maxXOR=INT_MIN;
	t2.insert(0);
	int *maxXORlistFromEnd=new int[n];
	for(int i=n-1;i>=0;i--)
	{
		prevXOR^=arr[i];
		t2.insert(prevXOR);
		maxXOR=max(maxXOR,t2.xorWithBestMatch(prevXOR));
		maxXORlistFromEnd[i]=maxXOR;
	}

	prevXOR=0;
	maxXOR=INT_MIN;
	t1.insert(0);
	for(int i=0;i<n-1;i++)
	{
		prevXOR^=arr[i];
		t1.insert(prevXOR);
		maxXOR=max(maxXOR,t1.xorWithBestMatch(prevXOR));
		res=max(res,maxXOR+maxXORlistFromEnd[i+1]);
	}

	return res;
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
	cout<<findMaxXOR(arr,n)<<endl;
	return 0;
}