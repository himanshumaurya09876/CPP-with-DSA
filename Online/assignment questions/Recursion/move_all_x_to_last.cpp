//move all x to last

#include<iostream>
#include<string>
using namespace std;

string moveX(string input,string output="",int count=0)
{
    if(input.length()==0)
    {
        for(int i=0;i<count;i++)
        {
            output+="x";
        }
        return output;
    }
    if(input[0]=='x')
    {
        count++;
    }
    else
    {
        output+=input[0];
    }
    input=input.substr(1);
    return moveX(input,output,count);
}

int main() {
    string str;
    cin>>str;
    cout<<moveX(str);
	return 0;
}