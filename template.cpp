#include<iostream>
#include<vector>
using namespace std;



template <class T> T Y_max( T a,  T b)
{
	return a>b ? a : b;
}
int Y_max(int a, int b)
{
	return a>b ? a : b;
}


template<class T>class Y_stack
{
	vector<T>stack;
public:
	void pop()
	{
		stack.pop_back();
	}
	void push(T&& a)
	{
		stack.push_back(a);
	}
	T& top()
	{
		return stack.back();
	}
};


class A
{
	int value = 0;
	char* p;
public:
	A(int v)
	{
		value = v;
		p = new char[100];
	}
	A(const A& other):A(other.value)
	{

	}
	A(A&& other)
	{
		p = other.p;
		other.p = nullptr;
		value = other.value;
	}
	~A()
	{
		delete p;
	}
	//复制赋值运算符
	A& operator=(const A& other)
	{
		delete this->p;
		this->p = new char[100];
		this->value = other.value;
		return *this;
	}
	//移动赋值运算符
	A& operator=(A&& other)
	{
		p = other.p;
		other.p = nullptr;
		value = other.value;
		return *this;
	}
	operator int()
	{
		return value;
	}
};
template<class T> void exchange(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}



void Y_print()
{
	cout << endl;
}
//void Y_print(int a1)
//{
//	cout << a1 << " ";
//	Y_print();
//}
//void Y_print(double a1, int a2)
//{
//	cout << a1 << " ";
//	Y_print(a1, a2);
//}
//void Y_print(int a1,double a2,int a3)
//{
//	cout << a1 << " ";
//	Y_print(a2,a3);
//}
//void Y_print(char* a1,int a2,double a3,int a4)
//{
//	cout << a1 << " ";
//	Y_print(a2,a3,a4);
//}
template<class T, class...args> void Y_print(T t, args ...a)
{
	cout << t << " ";
	Y_print(a...);
}

int main()
{
	Y_print(5.3, "dasf", 7, 0.2, 5);


	//隐式推导
	int i = 2, j = 5;
	cout << Y_max(i, j) << endl;
	//显式推导
	cout << Y_max<double>(2,5.5) << endl;
	//指定模板推导
	int m = 3, n = 4;
	cout << Y_max<>(m, n) << endl;

	Y_stack<int> y;
	y.push(1);
	y.push(4);
	cout << y.top() << endl;

	A a(100);
	A b(20);
	exchange(a, b);
	cout << a << ' ' << b;
	return 0;
}