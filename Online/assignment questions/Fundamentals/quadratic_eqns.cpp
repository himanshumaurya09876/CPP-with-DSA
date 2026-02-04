#include<iostream>
#include<math.h>
using namespace std;
int main() {
    int a,b,c,d;
    int r1,r2;
    cin>>a>>b>>c;
    d=b*b-4*a*c;
    if(d<0)
        cout<<"Imaginary";
    else
    {
        r1=(-b+sqrt(d))/(2*a);
        r2=(-b-sqrt(d))/(2*a);
        if(d==0)
            cout<<"Real and Equal"<<endl;
        else
            cout<<"Real and Distinct"<<endl;
        cout<<r2<<" "<<r1;
    }
	return 0;
}