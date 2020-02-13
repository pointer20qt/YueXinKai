#pragma once
#include<string>
using namespace std;
class teacher
{
	string teacherName;
public:
	teacher();
	teacher(string name);
	teacher(const teacher& t);
	~teacher();
};

