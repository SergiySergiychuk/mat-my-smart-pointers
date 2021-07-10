#pragma once
#include<iostream>

template<class T>
class MySharedPointer
{
private:
	T* mp_data;
	int* mp_ref_count;

public:
	MySharedPointer() : mp_data(nullptr), mp_ref_count(new int(0)) {}
	MySharedPointer(T* ptr) : mp_data(ptr), mp_ref_count(new int(1)) {}
	MySharedPointer(const MySharedPointer& new_ptr)
	{
		mp_data = new_ptr.mp_data;
		mp_ref_count = new_ptr.mp_ref_count;
		(*mp_ref_count)++;
	}
	MySharedPointer& operator=(const MySharedPointer& new_ptr)
	{
		Clean();
		mp_data = new_ptr.mp_data;
		mp_ref_count = new_ptr.mp_ref_count;
		(*mp_ref_count)++;
		return *this;
	}
	MySharedPointer(MySharedPointer&& old_ptr)
	{
		mp_data = old_ptr.mp_data;
		mp_ref_count = old_ptr.mp_ref_count;
		old_ptr.mp_data = nullptr;
		*(old_ptr.mp_ref_count) = 0;
	}
	MySharedPointer& operator=(MySharedPointer&& old_ptr)
	{
		Clean();
		mp_data = old_ptr.mp_data;
		mp_ref_count = old_ptr.mp_ref_count;
		old_ptr.mp_data = nullptr;
		*(old_ptr.mp_ref_count) = 0;
	}
	T& operator*()
	{
		return *mp_data;
	}
	T* operator->()
	{
		return mp_data;
	}
	~MySharedPointer()
	{
		Clean();
	}
private:
	void Clean()
	{
		(*mp_ref_count)--;
		if (*mp_ref_count == 0)
		{
			if (mp_data)
			{
				delete mp_data;
			}
			delete mp_ref_count;
		}
	}
};