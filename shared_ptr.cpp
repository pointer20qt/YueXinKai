//shared����ָ����Ҫ�ķ���
/*
�޲ι��죬����ָ�빹�죬�������죬�ƶ����죬������ֵ���ƶ���ֵ,��������������
reset(T*)�滻���� reset() ���ٶ���
operator*() operator->()
get()�����ָ��
use_count() ������ü���
unique() �жϵ�ǰ�Ƿ�Ψһ  use_count()==1
operator bool() �Ƿ��������
*/
template<class T>class Ref
{
	T* obj = nullptr;
	int y_count = 0;
public:
	Ref(T* p)
	{
		obj = p;
		y_count++;
	}
	inline void increase()
	{
		y_count++;
	}
	inline void reduce()
	{
		y_count--;
		if (y_count == 0)
		{
			delete obj;
			delete this;
		}
	}
};
template<class T>class Y_sharedPtr
{
	T* ptr = nullptr;
public:
	Y_sharedPtr()
	{

	}
	Y_sharedPtr(T* p)
	{
		ptr = new Ref<T>(p);
	}
	Y_sharedPtr(const Y_sharedPtr& other)
	{
		ptr = other.ptr;
		if (ptr)
		{
			ptr->increase();
		}
	}
	Y_sharedPtr(Y_sharedPtr&& other)
	{
		ptr = other.ptr;
		other.ptr = nullptr;
	}
	Y_sharedPtr& operator = (const Y_sharedPtr& other)
	{
		if (ptr)
		{
			ptr->reduce();
		}
		ptr = other.ptr;
		if (other.ptr)
		{
			ptr->increase();
		}
		return *this;
	}
	Y_sharedPtr& operator=(Y_sharedPtr&& other)
	{
		if (ptr)
		{
			ptr->reduce();
		}
		ptr = other.ptr;
		delete other.ptr;
		return *this;
	}
	void swap(Y_sharedPtr& other)
	{
		swap(ptr, other.ptr);
	}
	void reset(T* p=nullptr)
	{
		if (ptr)
		{
			ptr->reduce();
		}
		if (p)
		{
			ptr = new Ref<T>(p);
		}
		else
		{
			ptr = nullptr;
		}
	}
	T* get()
	{
		if (ptr)
		{
			return ptr->obj;
		}
		else
		{
			return (T*)nullptr;
		}
	}
	T& operator*()
	{
		return *get();
	}
	T* operator->()
	{
		return get();
	}
	int use_count()
	{
		if (ptr)
		{
			return ptr->y_count;
		}
		else
		{
			return 0;
		}
	}
	bool unique()
	{
		if (ptr)
		{
			return ptr->y_count == 1;
		}
		else
		{
			return false;
		}
	}
	operator bool()
	{
		return ptr != nullptr;
	}
	~Y_sharedPtr()
	{
		if (ptr)
		{
			ptr->reduce();
		}
	}
};