//Replace all pi

#include<iostream>
using namespace std;

void replacePI(string input,string output="")
{
    if(input.length()==0)
    {
        cout<<output<<endl;
        return;
    }
    if(input[0]=='p' && input[1]=='i')
    {
        output+="3.14";
        input=input.substr(2);
    }
    else
    {
        output+=input[0];
        input=input.substr(1);
    }
    replacePI(input,output);
}

int main() {
    int n;
    cin>>n;
    while(n>0)
    {
        string str;
        cin>>str;
        replacePI(str);
        n--;
    }
	return 0;
}