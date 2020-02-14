#include<iostream>
using namespace std;

class people
{
public:
	people()
	{
		cout << "people出生" << endl;
	}
	virtual void doWork()
	{
		cout << "吃饭" << endl;
	}
	virtual ~people()
	{
		cout << "people死" << endl;
	}
};
class student :public people
{
public:
	student()
	{
		cout << "student出生" << endl;
	}
	void doWork()
	{
		cout << "学习" << endl;
	}
	~student()
	{
		cout << "student死" << endl;
	}
};

int main()
{
	
	people* b = new student;
	b->doWork();
	delete b;

	return 0;
}


