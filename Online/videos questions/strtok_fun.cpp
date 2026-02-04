//strtok function
#include <iostream>
//#include <string>
#include <cstring>

using namespace std;

int main(int argc, char const *argv[])
{
	char str[]="Hello, I am Himanshu maurya";
	char *ptr;
	ptr=strtok(str," ");
	// cout<<ptr<<endl;
	// ptr=strtok(str," ");
	cout<<ptr<<endl;
	ptr=strtok(NULL," ");
	cout<<ptr<<endl;
	ptr=strtok(NULL," ");
	cout<<ptr<<endl;
	ptr=strtok(NULL," ");
	cout<<ptr<<endl;
	ptr=strtok(NULL," ");
	cout<<ptr<<endl;
	return 0;
}