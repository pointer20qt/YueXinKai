#include<iostream>
using namespace std;

class people
{
public:
	people()
	{
		cout << "people����" << endl;
	}
	virtual void doWork()
	{
		cout << "�Է�" << endl;
	}
	virtual ~people()
	{
		cout << "people��" << endl;
	}
};
class student :public people
{
public:
	student()
	{
		cout << "student����" << endl;
	}
	void doWork()
	{
		cout << "ѧϰ" << endl;
	}
	~student()
	{
		cout << "student��" << endl;
	}
};

int main()
{
	
	people* b = new student;
	b->doWork();
	delete b;

	return 0;
}


