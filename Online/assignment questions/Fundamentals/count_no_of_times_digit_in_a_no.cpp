#include<iostream>
using namespace std;
int fun(int n,int d)
{
    int count=0;
    while(n>0)
    {
        int m=n%10;
        if(m==d)
            count++;
        n=n/10;
    }
    return count;
}
int main() {
    int n,d;
    cin>>n>>d;
    cout<<fun(n,d);
	return 0;
}