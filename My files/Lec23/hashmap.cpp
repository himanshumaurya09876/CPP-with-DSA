//hashing...
#include <iostream>
#include <string>
using namespace std;

template <typename t1,typename t2>
class node
{
public:
	t1 key;
	t2 value;
	node<t1,t2>* next;

	node(t1 k,t2 val)
	{
		key=k;
		value=val;
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

template <typename t1,typename t2>
class hashMap//also called hashTable
{
private:
	int totalSize;
	int currSize;
	node<t1,t2> **arr;

	int hashFun(t1 key)//multiplicative method of hashing
	{
		int l=key.length();
		int idx=0;
		int multiFact=47;//multilication factor
		int res=1;
		for(int i=0;i<l;i++)
		{
			idx=(idx%totalSize + (((key[l-1-i]) % totalSize)*(res%totalSize))%totalSize )%totalSize;
			res=((res%totalSize)*(multiFact%totalSize))%totalSize;
		}
		return idx;
	}

	void rehash()
	{
		node<t1,t2>** oldArr=arr;
		int oldSize=totalSize;
		totalSize*=2;
		currSize=0;
		arr=new node<t1,t2>*[totalSize];
		for(int i=0;i<totalSize;i++)
		{
			arr[i]=NULL;
		}
		for(int i=0;i<oldSize;i++)
		{
			//cout<<oldArr[i]<<endl;
			if(oldArr[i]!=NULL)
			{
				node<t1,t2>*temp=oldArr[i];
				//cout<<"rehash "<<temp->key<<" "<<temp->value<<endl;
				while(temp!=NULL)
				{
					//cout<<"rehash "<<temp->key<<" "<<temp->value<<endl;
					insert(temp->key,temp->value);
					temp=temp->next;
				}
			}
		}
		//delete the old hashmap
		for(int i=0;i<oldSize;i++)
		{
			delete oldArr[i];
		}
		delete oldArr;
	}
public:
	hashMap(int size=5)
	{
		totalSize=size;
		currSize=0;
		arr=new node<t1,t2>*[totalSize];
		for(int i=0;i<totalSize;i++)
		{
			arr[i]=NULL;
		}
	}

	void insert(t1 key,t2 value)
	{
		int idx=hashFun(key);
		//cout<<idx<<" "<<key<<endl;
		node<t1,t2>* newnode=new node<t1,t2>(key,value);
		currSize++;
		if(arr[idx]==NULL)
		{
			arr[idx]=newnode;
		}
		else
		{
			//insertion at head of LL ->O(1)
			newnode->next=arr[idx];
			arr[idx]=newnode;

			//insertion at tail of LL ->O(size of LL)
			// while(temp->next!=NULL)
			// {
			// 	temp=temp->next;
			// }
			// temp->next=new node<t1,t2>(key,value);

			//now check for load factor
		}
		float loadFact=(float)currSize/(float)totalSize;
		if(loadFact>0.5)
		{
			//cout<<"rehashing..."<<endl;
			rehash();
		}
	}

	t2* find(t1 key)//or search
	{
		int idx=hashFun(key);
		node<t1,t2>* temp=arr[idx];
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

	void deleteNode(t1 key)
	{
		int idx=hashFun(key);
		node<t1,t2>* temp=arr[idx];
		if(temp->key==key)
		{
			arr[idx]=temp->next;
			delete temp;
		}
		else
		{
			while(temp->next!=NULL)
			{
				if(temp->next->key==key)
				{
					break;
				}
				temp=temp->next;
			}
		}

		if(temp->next!=NULL)
		{
			node<t1,t2>*temp1=temp->next;
			temp->next=temp1->next;
			delete temp1;
		}
	}

	void print()
	{
		for(int i=0;i<totalSize;i++)
		{
			node<t1,t2>*temp=arr[i];
			cout<<i<<" -> ";
			while(temp!=NULL)
			{
				cout<<"("<<temp->key<<","<<temp->value<<") -> ";
				temp=temp->next;
			}
			cout<<"NULL"<<endl;
		}
	}

	t2& operator[](t1 key)
	{
		t2* temp=find(key);
		if(temp==NULL)
		{
			t2 garbageValue;
			insert(key,garbageValue);
			temp=find(key);
		}
		return *temp;
	}
};

int main(int argc, char const *argv[])
{
	hashMap<string,int> h;
	h.insert("Apple",50);
	h.insert("Mango",500);
	h.insert("Guava",100);
	h.insert("Orange",90);
	h["Banana"]=560;
	h["Papaya"]=630;
	h.print();
	h["Papaya"]=1230;
	cout<<"_________________________________________________________"<<endl;
	h.print();
	h.deleteNode("Banana");
	h.deleteNode("Papaya");
	h.deleteNode("Orange");
	cout<<"_________________________________________________________"<<endl;
	h.print();
	return 0;
}