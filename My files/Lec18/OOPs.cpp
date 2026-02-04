//object oriented programming

#include <iostream>
#include <cstring>
//#include <string>
using namespace std;

class Car
{
private:
	int price;
public:
	string name;
	int mileage;
	char* color;//using this (without DMA and setting an address to color) will create an string in ROM and then color will point to that new 
	//string but if we will try to change a particular 
	//character of that string then it will give an error of segmentation fault or permission denied because it is read only memory so you don't
	//have permission to change something there, but you can create new one and color start pointing to that location

	//default constructor
	Car()
	{
		cout<<"Default constructor"<<endl;
		color=new char[10];//using DMA we make color to point here instead of any random memory location
	}

	//parameterized constructor
	Car(string n,int m,char* c,int p)
	{
		cout<<"Parameterized constructor"<<endl;
		name=n;
		mileage=m;
		color=new char[10];//using DMA we make color to point here instead of any random memory location
		//color=c;
		strcpy(color,c);//we are using strcpy because it copy c in color char by char
		//color and c are of char* type so only strcpy will work
		price=p;
	}

	// //copy constructor->Shallow copy
	// Car(Car &X)//it is called by reference because in call by value a copy of that object will be required to create here but there will no longer
	// //default constructor to do so (because we created our own copy constructor) so to create copy of that object during call it will use our own
	// //copy constructor which will finally result in an infinite loop 
	// {
	// 	cout<<"Shallow copy constructor"<<endl;
	// 	name=X.name;
	// 	mileage=X.mileage;
	// 	price=X.price;
	// 	color=X.color;
	// }

	//Deep copy constructor
	Car(Car &X)
	{
		cout<<"Deep copy constructor"<<endl;
		name=X.name;
		mileage=X.mileage;
		price=X.price;
		color=new char[10];
		// color=X.color;
		strcpy(color,X.color);
	}

	//Assignment operator
	void operator=(Car X)
	{
		cout<<"Assignment operator"<<endl;
		name=X.name;
		mileage=X.mileage;
		price=X.price;
		//color=new char[10];//it is not needed here because assignment operator will be used only after calling constructor 
		//so color will already point to a new DMA you have to just put some value there
		// color=X.color;
		strcpy(color,X.color);
	}

	void set_price(int p)
	{
		price=p;
	}

	int get_price()
	{
		return price;
	}

	void printCar()
	{
		cout<<"Name= "<<name<<endl;
		cout<<"Price= "<<price<<endl;
		cout<<"Mileage= "<<mileage<<endl;
		cout<<"Color= "<<color<<endl;
		cout<<"***************************************************************************"<<endl;
	}
};

// ostream operator<<(ostream& dout,Car &X)//we can also do this but it will not work for cascaded output like cout<<X<<A<<endl; etc
// {                                       //similarly for istream (ie cascading in cin)
// 	//X.printCar();
// 	dout<<"Name= "<<X.name<<endl;
// 	dout<<"Price= "<<X.get_price()<<endl;
// 	dout<<"Mileage= "<<X.mileage<<endl;
// 	dout<<"Color= "<<X.color<<endl;
// 	dout<<"***************************************************************************"<<endl;
// 	return dout;
// }

ostream& operator<<(ostream& dout,Car &X)
{
	//X.printCar();
	dout<<"Name= "<<X.name<<endl;
	dout<<"Price= "<<X.get_price()<<endl;
	dout<<"Mileage= "<<X.mileage<<endl;
	dout<<"Color= "<<X.color<<endl;
	dout<<"***************************************************************************"<<endl;
	return dout;
}

istream& operator>>(istream& din,Car &X)
{
	int p;
	din>>X.name>>p>>X.mileage>>X.color;
	X.set_price(p);
	return din;
}

int main(int argc, char const *argv[])
{
	// Car *A=new Car();
	// A->name="car_A";
	// A->mileage=100;
	// //A->price=500000; because price is private
	// A->set_price(500000);
	// A->color="Blue";

	// Car *B=new Car("car_B",200,"red",4552110);
	// A->printCar();
	// B->printCar();

	// Car C=A;
	// C.printCar();

	// Car D(B);//here copy constructor will be implicitly called
	// D.printCar();

	char ch[]="blue";
	Car E("car_E",500,ch,452022636);
	E.printCar();

	// //E.color[2]='a';//it will give some error, reason discussed above
	// E.color[2]='a';//used DMA so not give error
	// E.printCar();

	// Car F(E);//it will also call copy constructor
	// F.printCar();
	// F.color[2]='u';
	// F.printCar();
	// E.printCar();

	// Car G;//here default constructor will be called
	// //G.printCar();
	// G=E;//here overloaded assignment operator will be called
	// G.printCar();

	Car H;
	cin>>H;
	cout<<H<<endl;
	return 0;
}