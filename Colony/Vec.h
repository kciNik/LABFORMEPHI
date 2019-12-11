#ifndef VECTOR_H
#define VECTOR_H
#pragma once

namespace Tuliphus {
	template <class T>
	class VecIt;

	template <class T>
	class Vec
	{
		friend class VecIt<T>;
	private:
		T *data;
		int size;
		int cap;
		int GetPos(const int&) const;
	public:
		typedef VecIt<T> Iterator;
		Iterator begin();
		Iterator end();
		Iterator find(const int&) const;
		Vec(int = 1);
		Vec(Vec&);
		Vec operator=(const Vec&);
		int GetCapacity() const;
		int GetSize() const;
		T& operator [](int);
		void push_back(T);
		void clear();
		void create(const int &i);
		void remove(const int &i);
		void resize(const int &n);
		~Vec<T>(void);

	};

	template <class T>
	class VecIt
	{
	private:
		T *cur;
	public:
		VecIt() : cur(0) {}
		VecIt(T *n) : cur(n) {}
		bool operator!=(const VecIt&) const;
		bool operator==(const VecIt&) const;
		T& operator *();
		T* operator ->();
		VecIt<T>& operator ++();
	};

	template<class T>
	int Vec<T>::GetPos(const int &s) const
	{
		for (int i = 0; i < size; ++i)
			if (i == s)
				return i;
		return -1;
	}

	template<class T>
	Vec<T>::Iterator Vec<T>::begin()
	{
		return Iterator(data.get());
	}

	template<class T>
	Vec<T>::Iterator Vec<T>::end()
	{
		return Iterator(data.get() + size);
	}

	template<class T>
	Vec<T>::Iterator Vec<T>::find(const int &s) const
	{
		int i = getPos(s);
		if (i < 0)
			i = size;
		return Iterator(this->arr + i);
	}

	template <class  T>
	Vec<T>::Vec(int n)
	{
		create(n);
	}

	template <class  T>
	Vec<T>::~Vec(void)
	{
		delete[] data;
	}

	template <class  T>
	int Vec<T>::GetSize(void) const
	{
		return size;
	}

	template <class  T>
	T& Vec<T>::operator[](int i)
	{
		return data[i];
	}

	template <class T>
	Vec<T> Vec<T>::operator=(const Vec&a)
	{
		size = a.size;
		for (int i = 0; i != a.size; ++i) {
			this->date[i] = a.data[i];
		}
		return *this;
	}

	template<class T>
	bool VecIt<T>::operator!=(const VecIt &v) const
	{
		return cur != v.cur;
	}

	template <class T>
	bool VecIt<T>::operator==(const VecIt &v) const
	{
		return cur == v.cur;
	}

	template<class T>
	T & VecIt<T>::operator*()
	{
		return *cur;
	}

	template<class T>
	T * VecIt<T>::operator->()
	{
		return cur;
	}

	template<class T>
	VecIt<T>& VecIt<T>::operator++()
	{
		++cur;
		return *this;
	}

	template <class T>
	Vec<T>::Vec(Vec&a) {
		this->size = a.size;
		for (int i = 0; i != a.size; ++i) {
			this->date[i] = a.data[i];
		}
	}

	template <class T>
	void Vec<T>::push_back(T val) {
		T* newdata;
		if (size > cap) {
			cap = cap * 2;
			newdata = new T[cap];
			for (int i = 0; i < size; i++)
				newdata[i] = data[i];
			delete[] data;
			data = newdata;
		}
		data[size] = val;
		size++;
	}

	template <class  T>
	int Vec<T>::GetCapacity() const
	{
		return cap;
	}

	template <class  T>
	void Vec<T>::remove(const int &i)
	{
		T* newdata = new T[cap];
		bool f = false;

		for (int j = 0; j < this->size; j++)
		{
			if (j == i)
			{
				f = true;
			}
			if (f)
			{
				newdata[j - 1] = this->data[j];
			}
			else {
				newdata[j] = this->data[j];
			}
		}
		this->size -= 1;
		delete[] this->data;
		this->data = newdata;
	}

	template <class  T>
	void Vec<T>::resize(const int &n)
	{
		T* newdata = new T[n];
		this->cap = n;
		this->size = n > this->size ? this->size : n;
		for (int i = 0; i < this->size; i++)
		{
			newdata[i] = this->data[i];
		}
		delete[] this->data;
		this->data = newdata;
	}


	template <class  T>
	void Vec<T>::clear()
	{
		delete[] this->data;
		this->size = 0;
		this->cap = 1;
		this->data = new T[1];
	}

	template <class  T>
	void Vec<T>::create(const int &i) {
		if (this->data)
			delete[] data;
		size = 0;
		cap = i;
		data = new T[i];
	}
}
#endif
