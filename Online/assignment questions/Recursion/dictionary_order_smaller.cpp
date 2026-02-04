//al permutations which are smaller than the given string in dictionary order
#include<iostream>
#include<string>
using namespace std;

void dictionary(string input,string vin,int i=0,string output="")
{
	int l=vin.length();
	if(l==0)
	{
		if(output!=input)
			cout<<output<<endl;
		return;
	}
	for(int j=0;j<l;j++)
	{
		char ch=vin[j];
		//cout<<"ch "<<ch<<endl;
		if(ch<=input[i])
		{
			//cout<<"vin "<<vin.substr(0,j)+vin.substr(j+1)<<endl;
			dictionary(input,vin.substr(0,j)+vin.substr(j+1),i+1,output+ch);
		}
		cout<<endl;
	}
}

int main() {
	string str;
	cin>>str;
	dictionary(str,str);
	return 0;
}
