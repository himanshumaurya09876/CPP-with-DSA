#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
int main() {
    int n,i,l=0;
    cin>>n;
    for(i=0;i<n;i++)
    {
        int ans=0;
        char arr[17];
        cin>>arr;
        l=strlen(arr);
        for(int j=0;j<l;j++)
        {
            if(arr[j]=='1')
                ans=ans+pow(2,l-1-j);
        }
        cout<<ans<<endl;
    }
	return 0;
}