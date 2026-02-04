//is Armstrong number

#include<iostream>
using namespace std;

bool fun(int n)
{
    int sum=0,num=n;
    while(n>0)
    {
        int d=n%10;
        sum=sum+d*d*d;
        n=n/10;
    }
    if(num==sum)
        return true;
    else
        return false;
}

int main() {
    int n;
    cin>>n;
    int r=fun(n);
    if(r==1)
        cout<<"true";
    else
        cout<<"false";
	return 0;
}