//sort game

#include<bits/stdc++.h>
using namespace std;
struct employee
{
	string name;
	int salary;
};
bool compare(struct employee e1,struct employee e2)
{
	if(e1.salary!=e2.salary)
	{
		return e1.salary>e2.salary;
	}
	return e1.name<e2.name;
}
int main() {
    struct employee e1[100000];
	int n,x;
	cin>>x>>n;
    for(int i=0;i<n;i++)
    {
        cin>>e1[i].name>>e1[i].salary;
    }
    sort(e1,e1+n,compare);
    for(int i=0;i<n;i++)
    {
        if(e1[i].salary>=x)
        {
            cout<<e1[i].name<<" "<<e1[i].salary<<endl;
        }
    }
	return 0;
}