#include <string>
using namespace std;
template <typename T>
class node
{
public:
	string key;
	T value;
	node<T> *next;

	node(string str,T data)
	{
		key=str;
		value=data;
		next=NULL;
	}

	~node()
	{
		if(next!=NULL)
		{
			delete next;
		}
	}
};

template <typename T>
class hashmap
{
private:
	int cs;
	int ts;
	node<T> **container;

	int hashFunction(string key)
	{
		int idx=0;
		int l=key.length();
		int k=1;
		for(int i=0;key[i]!='\0';i++)
		{
			idx=(idx+(key[l-1-i]*k)%ts)%ts;
			k=(k*37)%ts;
		}
		return idx;
	}

	void rehash()
	{
		node<T>** oldContainer=container;
		int oldTS=ts;
		ts=2*ts;
		cs=0;
		container=new node<T>*[ts];
		for(int i=0;i<ts;i++)
		{
			container[i]=NULL;
		}

		for(int i=0;i<oldTS;i++)
		{
			node<T>* temp=oldContainer[i];
			while(temp!=NULL)
			{
				// cout<<temp->key<<endl;
				insert(temp->key,temp->value);
				temp=temp->next;
			}
			delete oldContainer[i];
		}

		delete[] oldContainer;
	}
public:
	hashmap(int ds=5)
	{
		cs=0;
		ts=ds;
		container=new node<T>*[ts];
		for(int i=0;i<ts;i++)
		{
			container[i]=NULL;
		}
	}

	void insert(string key,T value)
	{
		int idx=hashFunction(key);
		// cout<<idx<<" "<<key<<endl;
		node<T>* newnode=new node<T>(key,value);
		newnode->next=container[idx];
		container[idx]=newnode;
		cs++;
		float loadFactor=(float)cs/ts;
		if(loadFactor>0.7)
		{
			// cout<<"Load factor = "<<loadFactor<<endl;
			cout<<endl<<"Rehashing........"<<endl;	
			rehash();
		}
	}

	void print()
	{
		cout<<endl;
		for(int i=0;i<ts;i++)
		{
			cout<<"Row-"<<i<<" -> ";
			node<T> *temp=container[i];
			while(temp!=NULL)
			{
				cout<<temp->key<<" -> ";
				temp=temp->next;
			}
			cout<<endl;
		}
	}

	T* search(string key)
	{
		int idx=hashFunction(key);
		node<T> *temp=container[idx];
		while(temp!=NULL)
		{
			if(temp->key==key)
			{
				return &(temp->value);
			}
			temp=temp->next;
		}
		return NULL;
	}

	void erase(string key)
	{
		int idx=hashFunction(key);
		// cout<<idx<<endl;
		node<T> *temp=container[idx];
		// cout<<temp->key;
		if(temp->key==key)
		{
			container[idx]=NULL;
			delete temp;
			return;
		}
		while(temp!=NULL && temp->next!=NULL)
		{
			if(temp->next->key==key)
			{
				node<T>* toBeDeleted=temp->next;
				temp->next=toBeDeleted->next;
				delete toBeDeleted;
				return;
			}
			temp=temp->next;
		}
	}

	T& operator[](string key)
	{
		T* block=search(key);
		if(block==NULL)
		{
			T garbage;
			insert(key,garbage);
			block=search(key);
		}
		return *block;
	}
};