#include <iostream>
#include <unordered_map>
#define hashmap unordered_map<char,node*>

using namespace std;

class node
{
public:
	char data;
	hashmap h;
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
				return false;
			}
		}
		return temp->isTerminated;
	}
};

int main(int argc, char const *argv[])
{
	string arr[10]={"apple","mango","ape","newzealand","news","mangoman","bat","batman","zoo","zoological"};
	trie t;
	for(int i=0;i<10;i++)
	{
		t.insert(arr[i]);
	}
	string str;
	cin>>str;
	if(t.search(str))
	{
		cout<<str<<" is present"<<endl;
	}
	else
	{
		cout<<str<<" is not present"<<endl;
	}
	return 0;
}