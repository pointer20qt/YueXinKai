#include "school.h"
#include<iostream>
using namespace std;
school::school()
{
	schoolName = '0';
	cout << "无参构造：" << schoolName << "开学" << endl;
}
school::school(string name, string add):schoolName(name), address(add)
{
	cout << "有参构造：" << schoolName << "开学" << endl;
	t = new teacher("Mr杨");
}
school::school(const school& s):schoolName(s.schoolName), address(s.address)
{
	cout << "(深)拷贝构造：" << schoolName << "开学" << endl;
	t = new teacher(*(s.t));
}
school::school(school && s) : schoolName(s.schoolName), address(s.address)
{
	cout << "移动构造：" << schoolName << "开学" << endl;
	t = s.t;
	s.t = NULL;
}
school::~school()
{
	cout << schoolName << "放假" << endl;
	delete t;
}
