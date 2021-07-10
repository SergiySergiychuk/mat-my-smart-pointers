
template <class T>
class MyUniquePointer
{
private:
	T* mp_data;

public:
	MyUniquePointer() : mp_data(nullptr) {}
	MyUniquePointer(T* ptr) : mp_data(ptr) {}
	MyUniquePointer(MyUniquePointer&& old_ptr)
	{
		mp_data = old_ptr.mp_data;
		old_ptr.mp_data = nullptr;
	}
	MyUniquePointer& operator=(MyUniquePointer&& old_ptr)
	{
		mp_dat = old_ptr.mp_data;
		old_ptr.mp_data = nullptr;
	}
	T* operator->()
	{
		return mp_data;
	}
	T& operator*()
	{
		return *mp_data;
	}
	T* release() noexcept
	{
		T* buff = mp_data;
		mp_data = nullptr;
		return buff;
	}
	void reset(T* new_ptr) noexcept
	{
		T* old_ptr = mp_data;
		mp_data = new_ptr;
		if (old_ptr)delete old_ptr;

	}
	~MyUniquePointer()
	{
		if (mp_data)
			delete mp_data;
	}
	MyUniquePointer(const MyUniquePointer& ptr) = delete;
	MyUniquePointer& operator=(const MyUniquePointer& ptr) = delete;
};