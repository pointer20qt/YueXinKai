#include<iostream>
#include"school.h"
using namespace std;
#pragma comment(lib,"libtest.lib")

typedef class complex
{
	int real;
	int imagin;
public:
	complex(int x, int y) :real(x), imagin(y){}
	complex operator+(complex& c)
	{
		return complex(real + c.real, imagin + c.imagin);
	}
	string toString()
	{
		char px[30];
		sprintf(px, "%d+%di", real, imagin);
		return string(px);
	}
}com;



ostream& operator<<(ostream& o, complex& c)
{
	o << c.toString();
	return o;
}

int main()
{
	school byau("八一农大", "大庆");
	school bynk(move(byau));
	cout << "1" << endl;

	com x1(2, 5);
	com x2(3, 7);

	cout << x1 << " " << x2 << "  " << (x1 + x2) << endl;

	operator<<(operator<<(operator<<(cout, x1)<<" ", x2)<<"  ", x1 + x2)<<endl;

	return 0;
}