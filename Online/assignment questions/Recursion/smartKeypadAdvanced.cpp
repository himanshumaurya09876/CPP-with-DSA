#include<iostream>
#include<string>
using namespace std;
string searchIn[] = {
            "prateek", "sneha", "deepak", "arnav", "shikha", "palak",
            "utkarsh", "divyam", "vidhi", "sparsh", "akku"
    };
string table[] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };
bool isSubstr(string parent,string child)
{
	int pl=parent.length(),cl=child.length();
	char flag='n';
	int i=0,j=0;
	while(j<pl)
	{
		if(parent[j]==child[i])
		{
			i++;
			if(i==cl)
			{
				return true;
			}
			flag='y';
		}
		else if(flag=='y')
		{
			i=0;
			flag='n';
		}
		j++;
	}
	return false;
}
void genWords(string input,string output="")
{
    if(input[0]=='\0')
    {
        for(int i=0;i<11;i++)
        {
            if(isSubstr(searchIn[i],output))
            {
                cout<<searchIn[i]<<endl;
            }
        }
        return;
    }
    int n=input[0]-'0';
    int l=table[n].length();
    for(int i=0;i<l;i++)
    {
        genWords(input.substr(1),output+table[n][i]);
    }
}
int main() {
    string str;
    cin>>str;
    genWords(str);
	return 0;
}