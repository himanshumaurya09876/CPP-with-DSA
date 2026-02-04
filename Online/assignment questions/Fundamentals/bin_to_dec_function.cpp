#include<iostream>
#include<math.h>
using namespace std;

int btod(int n)
{
    int i=0,res=0;
    while(n>0)
    {
        if(n%10 == 1)
            res=res+pow(2,i);
        i++;
        n=n/10;
    }
    return res;
}

int main() {
    int n;
    cin>>n;
    cout<<btod(n);
	return 0;
}