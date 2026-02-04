//prime visits

#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    while(n>0)
    {
        int a,b,c=0,root;
        cin>>a>>b;
        if(a<2)
            a=2;
        for(int i=a;i<=b;i++)
        {
            int j=0;
            root=sqrt(i);
            for(j=2;j<=root;j++)
            {
                if(i%j==0)
                {
                    break;
                }
            }
            if(j>root)
            {
                c++;
            }
        }
        cout<<c<<endl;
        n--;
    }
	return 0;
}