#include<iostream>
#include<list>
#include<vector>
#include<Initializer_List>
#include<assert.h>
using namespace std;


class vec
{
	vector<int> p;
public:
	vec(initializer_list<int> a) :p(a)
	{
		int i = 0;
		while (i<a.size())
		{
			p[i]= *(a.begin() + i);
			i++;
		}
	}
	int& operator[](unsigned int index)
	{
		assert(index >= 0 && index < p.size());
		return p[index];
	}

};

int main()
{
	vec v({ 1, 2, 3, 4, 5, 6, 7 });
	cout<<v[2];

	return 0;
}