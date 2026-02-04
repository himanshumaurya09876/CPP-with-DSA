//phonebook
#include <iostream>
#include <unordered_map>
using namespace std;

class node
{
public:
	char data;
	unordered_map<char,node*> hash;
	string name;

	node(char ch)
	{
		data=ch;
		name="";
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

	void insert(string num,string name)
	{
		node* temp=root;
		for(int i=0;num[i]!='\0';i++)
		{
			if(temp->hash.count(num[i])<1)
			{
				node* child=new node(num[i]);
				temp->hash[num[i]]=child;
				temp=child;
			}
			else
			{
				temp=temp->hash[num[i]];
			}
		}
		temp->name=name;
	}

	string search(string num)
	{
		node* temp=root;
		for(int i=0;num[i]!='\0';i++)
		{
			if(temp->hash.count(num[i])>0)
			{
				temp=temp->hash[num[i]];
			}
			else
			{
				return "Does not exist";
			}
		}
		if(temp->name!="")
		{
			return temp->name;
		}
		return "Does not exist";
	}
};

int main(int argc, char const *argv[])
{
	trie phonebook;
	phonebook.insert("98756","abc");
	phonebook.insert("9855556","vdbdf");
	phonebook.insert("65665","vdfg");
	phonebook.insert("5454","umun");
	phonebook.insert("412121","dvrf");
	phonebook.insert("4546","dvgnhn");
	cout<<phonebook.search("98756")<<endl;
	cout<<phonebook.search("412121")<<endl;
	cout<<phonebook.search("9856")<<endl;
	return 0;
}