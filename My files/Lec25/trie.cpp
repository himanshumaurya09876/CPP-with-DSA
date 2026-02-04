//tries
#include <iostream>
#include <unordered_map>
using namespace std;

class node
{
public:
	char data;
	unordered_map<char,node*> hash;
	bool isTerminated;

	node(char ch)
	{
		data=ch;
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

	void insert(string str)
	{
		node* temp=root;
		for(int i=0;str[i]!='\0';i++)
		{
			if(temp->hash.count(str[i])<1)
			{
				node* child=new node(str[i]);
				temp->hash[str[i]]=child;
				temp=child;
			}
			else
			{
				temp=temp->hash[str[i]];
			}
		}
		temp->isTerminated=true;
	}

	bool search(string str)
	{
		node* temp=root;
		for(int i=0;str[i]!='\0';i++)
		{
			if(temp->hash.count(str[i])>0)
			{
				temp=temp->hash[str[i]];
			}
			else
			{
				return false;
			}
		}
		if(temp->isTerminated==true)
		{
			return true;
		}
		return false;
	}

	bool erase(string str,node* temp=root)
	{
		if(str[1]=='\0')
		{
			if(temp->isTerminated==true)
			{
				return false;
			}
			else
			{
				delete(temp);
				return true;
			}
		}
		if(temp->hash.count(str[0])>0)
		{
			if(erase(str.substr(1),temp->hash[str[0]]) && temp->isTerminated!=false)
			{
				delete(temp);
				return true;
			}
			else
			{
				return false;
			}
		}
	}

	// it will not delete but only make the string disappear 
	// void erase(string str)
	// {
	// 	node* temp=root;
	// 	for(int i=0;str[i]!='\0';i++)
	// 	{
	// 		if(temp->hash.count(str[i])>0)
	// 		{
	// 			temp=temp->hash[str[i]];
	// 		}
	// 		else
	// 		{
	// 			return;
	// 		}
	// 	}
	// 	temp->isTerminated=false;
	// }
};

int main(int argc, char const *argv[])
{
	trie t;
	t.insert("apple");
	t.insert("mango");
	t.insert("guava");
	t.insert("banana");
	string str="apple";
	t.erase(str);
	if(t.search(str))
	{
		cout<<"Found"<<endl;
	}
	else
	{
		cout<<"Not found"<<endl;
	}
	// if(t.search("app"))
	// {
	// 	cout<<"Found"<<endl;
	// }
	// else
	// {
	// 	cout<<"Not found"<<endl;
	// }
	return 0;
}