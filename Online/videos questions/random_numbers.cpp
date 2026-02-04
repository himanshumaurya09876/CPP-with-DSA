//let us generate random numbers
//actually they are called psuedo random numbers because they depend on the seed value 
//try to take seed value in srand() somrthing constant then see the random number it will be constant each time
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	srand(time(NULL));//current time is seed value because it is continuously changing so random number will be different each time
	cout<<"Enter range with in which the random should be: ";
	cin>>n;
	cout<<"Random number is: ";
	cout<<rand()%n;
	return 0;
}