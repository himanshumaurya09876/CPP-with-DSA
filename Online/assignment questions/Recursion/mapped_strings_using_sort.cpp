//mapped strings

#include<bits/stdc++.h>
using namespace std;
string str[100];
int i=0;
void intToWord(int n,string output="")
{
	if(n==0)
	{
		str[i]=output;
        i++;
		return;
	}
	char ch1=char(n%10+'A'-1);
	intToWord(n/10,ch1+output);
	int n1=n%100;
	if(n1<=26 && n1>9)
	{
		char ch2=char(n1+'A'-1);
		intToWord(n/100,ch2+output);
	}
}
// bool compare(string a,string b)
// {
//     return a>b;
// }
int main() {
	int n;
	cin>>n;
	intToWord(n);
    //sort(str,str+i,compare);
    sort(str,str+i);
    for(int j=0;j<i;j++)
    {
        cout<<str[j]<<endl;
    }
	return 0;
}
