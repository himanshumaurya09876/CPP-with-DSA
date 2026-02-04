#include <iostream>
//#include <cstdio>
using namespace std;

int main()
{
    int n,p;
    cout<<"Enter a number whose square root to be found and its precision"<<endl;
    cin>>n>>p;
    float ans=0;
    float inc=1;
    int terms=0;
    while(terms<=p)
    {
        while(ans*ans<=n)
        {
            ans=ans+inc;
        }
        ans=ans-inc;
        inc=inc/10;
        terms++;
    }
    cout<<"Square root of "<<n<<" is "<<ans;
    //printf("%0.6f",ans);
    return 0;
}
