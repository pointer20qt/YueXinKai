#pragma once
#include"teacher.h"
#include<string>
using namespace std;
class school
{
	string schoolName;
	string address;
	teacher* t;
public:
	school();
	school(string name,string add);
	school(const school& s);
	school(school && s);
	~school();
};

