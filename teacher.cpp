#include "teacher.h"
#include<iostream>

teacher::teacher()
{
	teacherName = "0��ʦ";
	cout << "�޲ι��죺" << teacherName << "�ϰ�" << endl;
}
teacher::teacher(string name)
{
	teacherName = name;
	cout << "�вι��죺" << teacherName << "�ϰ�" << endl;
	
}
teacher::teacher(const teacher& t)
{
	teacherName = t.teacherName;
	cout << "�������죺" << teacherName << "�ϰ�" << endl;
}

teacher::~teacher()
{
	cout << teacherName << "�°���" << endl;
}
