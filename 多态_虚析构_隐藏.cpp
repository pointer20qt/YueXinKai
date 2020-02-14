#include<iostream>
using namespace std;

class people
{
public:
	people()
	{
		cout << "people death" << endl;
	}
	virtual void doWork()
	{
		cout << "eat" << endl;
	}
	virtual ~people()
	{
		cout << "people death" << endl;
	}
};
class student :public people
{
public:
	student()
	{
		cout << "student death" << endl;
	}
	void doWork()
	{
		cout << "study" << endl;
	}
	~student()
	{
		cout << "student death" << endl;
	}
};

int main()
{
	
	people* b = new student;
	b->doWork();
	delete b;

	return 0;
}


