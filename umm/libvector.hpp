#pragma once

#include <initializer_list>
#include <stdexcept>

template<class T>
class Vector
{
private:
	unsigned int m_size;
	T* m_array;

public:
	Vector()
		: m_size(0), m_array(nullptr)
	{

	}

	Vector(unsigned int size)
		: m_size(size)
	{
		m_array = new T[size];
	}
	
	Vector(std::initializer_list<T> list)
		: Vector(list.size())
	{
		int i = 0;
		for (auto& element : list)
		{
			m_array[i] = element;
			++i;
		}
	}

	Vector(const Vector& v2)
	{
		m_size = v2.m_size;
		m_array = new T[v2.m_size];

		for (unsigned int i = 0; i < v2.m_size; ++i)
			m_array[i] = v2.m_array[i];
	}

	~Vector()
	{
		if (m_array != nullptr)
			delete[] m_array;
	}

	T& operator[](unsigned int index) const noexcept
	{
		return m_array[index];
	}

	T& at(unsigned int index) const
	{
		if (index > m_size)
			throw std::out_of_range("[libvector.hpp] index is out of range");

		return m_array[index];
	}

	T& front() const noexcept
	{
		return m_array[0];
	}

	T& back() const noexcept
	{
		return m_array[m_size];
	}

	T* data() const noexcept
	{
		return m_array;
	}

	unsigned int size() const noexcept
	{
		return m_size;
	}

	unsigned int capacity() const noexcept
	{
		return m_size * sizeof(T);
	}

	T* begin() const noexcept
	{
		return &m_array[0];
	}

	T* end() const noexcept
	{
		return &m_array[m_size];
	}

	void push_back(const T new_element) noexcept
	{
		T* buffer = new T[m_size + 1];
		
		for (unsigned int i = 0; i < m_size; ++i)
			buffer[i] = m_array[i];
		buffer[m_size] = new_element;

		delete[] m_array;

		m_array = new T[m_size + 1];

		for (unsigned int i = 0; i < (m_size + 1); ++i)
			m_array[i] = buffer[i];

		delete[] buffer;

		m_size += 1;
	}
};