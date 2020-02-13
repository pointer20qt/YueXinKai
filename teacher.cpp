#include "teacher.h"
#include<iostream>

teacher::teacher()
{
	teacherName = "0老师";
	cout << "无参构造：" << teacherName << "上班" << endl;
}
teacher::teacher(string name)
{
	teacherName = name;
	cout << "有参构造：" << teacherName << "上班" << endl;
	
}
teacher::teacher(const teacher& t)
{
	teacherName = t.teacherName;
	cout << "拷贝构造：" << teacherName << "上班" << endl;
}

teacher::~teacher()
{
	cout << teacherName << "下班了" << endl;
}
