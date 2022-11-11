#pragma once

template <typename T, class Deleter = std::default_delete<T>>

class unique_ptr {

private:

	T* ptr = nullptr;

	void clear()
	{
		if (ptr != nullptr)
		{
			Deleter deleter;
			deleter(ptr);
		}
	}

public:

	unique_ptr() : ptr(nullptr) {}                          // default constructor

	unique_ptr(T* ptr) : ptr(ptr) {}                        // constructor

	unique_ptr(const unique_ptr& other) = delete;             // copy constructor is deleted

	unique_ptr& operator=(const unique_ptr& other) = delete;  // copy assignment is deleted

	unique_ptr(unique_ptr&& other)                       // move constructor
	{
		// Transfer ownership of memory pointed by other
		this->ptr = other.ptr;
		other.ptr = nullptr;
	}

	void operator=(unique_ptr&& other) noexcept                   // move assignment
	{
		if (this != &other) {

			// clear existing data
			clear();

			// Transfer ownership of memory pointed
			this->ptr = other.ptr;
			other.ptr = nullptr;
		}

	}

	~unique_ptr()                                           // destructor
	{
		clear();
	}

	// obtaining pointer using arrow operator
	T* operator->()
	{
		return this->ptr;
	}

	// dereferencing underlying pointer
	T& operator*()
	{
		return *(this->ptr);
	}

	explicit operator bool() const noexcept                 // Bool Operator
	{
		if (this->ptr != nullptr) {
			return true;
		}
		return false;
	}

	//  releases the ownership of the object by the UniquePtr and returns a pointer to the object.
	T* Release()
	{
		T* tmp = this->ptr;

		this->Reset();

		return tmp;
	}

	//  resets the internal pointer to null
	void Reset()
	{
		this->ptr = nullptr;
	}

	//  swaps the managed object with another UniquePtr
	void Swap(unique_ptr<T>& other)
	{
		auto tmp = this->ptr;
		this->ptr = other.ptr;
		other.ptr = tmp;
	}

	//  swaps the managed object with a RawPointer
	void Swap(T*& other)
	{
		auto tmp = this->ptr;
		this->ptr = other;
		other = tmp;
	}
};

//  Referenzen:
//  [1] https://medium.com/swlh/c-smart-pointers-and-how-to-write-your-own-c0adcbdce04f
//  [2] https://en.cppreference.com/w/cpp/memory/unique_ptr