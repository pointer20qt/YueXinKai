#include "school.h"
#include<iostream>
using namespace std;
school::school()
{
	schoolName = '0';
	cout << "�޲ι��죺" << schoolName << "��ѧ" << endl;
}
school::school(string name, string add):schoolName(name), address(add)
{
	cout << "�вι��죺" << schoolName << "��ѧ" << endl;
	t = new teacher("Mr��");
}
school::school(const school& s):schoolName(s.schoolName), address(s.address)
{
	cout << "(��)�������죺" << schoolName << "��ѧ" << endl;
	t = new teacher(*(s.t));
}
school::school(school && s) : schoolName(s.schoolName), address(s.address)
{
	cout << "�ƶ����죺" << schoolName << "��ѧ" << endl;
	t = s.t;
	s.t = NULL;
}
school::~school()
{
	cout << schoolName << "�ż�" << endl;
	delete t;
}
