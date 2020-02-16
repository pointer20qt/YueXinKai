#include<iostream>
using namespace std;


template<class T>class my_ptr
{
	T* obj=nullptr;
public:
	my_ptr() = default;
	my_ptr(T* ptr)
	{
		obj = ptr;
	}
	my_ptr(my_ptr<T>& p)
	{
		obj = p.obj;
		p.obj = nullptr;
	}
	my_ptr& operator=(my_ptr<T>& ptr)
	{
		delete obj;
		obj = ptr.obj;
		ptr.obj = nullptr;
		return *this;
	}
	void reset(T* newptr)
	{
		delete obj;
		obj = newptr;
	}
	T* release()
	{
		auto temp = obj;
		obj = nullptr;
		return temp;
	}
	T& operator*()
	{
		return *obj;
	}
	T* operator->()
	{
		return obj;
	}
	~my_ptr()
	{
		delete obj;
	}
};