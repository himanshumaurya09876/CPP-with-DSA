// DIGITAL DICTIONARY
// Peter found a digital dictionary which is far better than normal dictionaries. The digital dictionary has an input field in which one can search any string and the dictionary displays all the words whose prefix is that input string. Now you are given a task to make your own digital dictionary. You will be given words that you can store in your database and then you need to design the search functionality. And if no such words are available, add this word to your dictionary.

// Input Format:
// Single integer N which denotes the number of words which are to be stored in the database of the dictionary. N lines of input, where in each line there is a string made up of lowercase/uppercase letter Single integer Q which denotes the number of queries. Q number of lines describing the query string on each line given by user.

// Constraints:
// 1≤N≤30000 sum(len(stringi))≤2∗10^5 1≤Q≤10^3

// Output Format
// If word with prefix exists in the database, then you need to print all the words with the given prefix in lexicographical order in separate lines else you need to print No suggestions

// Sample Input
// 4
// pet
// peter
// rat
// rack
// 5
// pe
// pet
// r
// rac
// rat
// Sample Output
// pet
// peter
// pet
// peter
// rack
// rat
// rack
// rat

#include <iostream>
#include <map>
using namespace std;

class node
{
public:
	char data;
	map<char,node*> h;
	bool isTerminated;

	node(char data)
	{
		this->data=data;
		isTerminated=false;
	}
};

class trie
{
private:
	node* root;  
public:
	trie()
	{
		root=new node('\0');
	}

	void insert(string data)
	{
		node* temp=root;
		for(int i=0;data[i]!='\0';i++)
		{
			char ch=data[i];
			if(temp->h.count(ch))
			{
				temp=temp->h[ch];
			}
			else
			{
				node* newnode=new node(ch);
				temp->h[ch]=newnode;
				temp=newnode;
			}
		}
		temp->isTerminated=true;
	}

	void print(node* temp,string data="")
	{
		if(temp->isTerminated)
		{
			cout<<data<<endl;
		}

		for(auto it:temp->h)
		{
			print(it.second,data+it.first);
		}
	}

	bool search(string data)
	{
		node* temp=root;
		for(int i=0;data[i]!='\0';i++)
		{
			char ch=data[i];
			if(temp->h.count(ch))
			{
				temp=temp->h[ch];
			}
			else
			{
				insert(data);
				return false;
			}
		}
		print(temp,data);
		return true;
	}
};

int main(int argc, char const *argv[])
{
	int n;
	trie t;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		string str;
		cin>>str;
		t.insert(str);
	}
	int q;
	cin>>q;
	for(int i=0;i<q;i++)
	{
		string str;
		cin>>str;
		if(!t.search(str))
		{
			cout<<"No suggestions"<<endl;
		}
	}
	return 0;
}