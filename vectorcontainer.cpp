#include <iostream>
#include <sstream>
#include <string>
#include <vector>

// std::out_of_range
#include <stdexcept>

template <class T>
class VectorContainer
{
public:
	VectorContainer();
	~VectorContainer();

	VectorContainer(std::vector<T>&);

	// regular vector functions
	void push_back(T);
	T operator[](unsigned int);
	typename std::vector<T>::iterator begin();
	typename std::vector<T>::iterator end();

	void copy(std::vector<T>*);
	void print();

	void addToElement(T, unsigned int);
	void subtractToElement(T, unsigned int);
	void multiplyToElement(T, unsigned int);
	void divideToElement(T, unsigned int);

	void addEachElement(T);
	void subtractEachElement(T);
	void multiplyEachElement(T);
	void divideEachElement(T);

private:
	std::vector<T> m_vector;
};

template <class T>
VectorContainer<T>::VectorContainer()
{
	// default constructor
	m_vector = std::vector<T>();
}

template <class T>
VectorContainer<T>::VectorContainer(std::vector<T>& _vector)
{
	m_vector = std::vector<T>();
	for (const auto& it : _vector)
		m_vector.push_back(it);
}

template <class T>
VectorContainer<T>::~VectorContainer()
{
	// deconstructor
}

template <class T>
void VectorContainer<T>::push_back(T value)
{
	m_vector.push_back(value);
}

template <class T>
T VectorContainer<T>::operator[](unsigned int element)
{
	if (element >= m_vector.size())
	{
		std::stringstream casted_element;
		casted_element << "Index " << element << " doesn't exist in the vector.";

		throw std::out_of_range(casted_element.str());
	}

	return m_vector[element];
}

template <class T>
typename std::vector<T>::iterator VectorContainer<T>::begin()
{
	return m_vector.begin();
}

template <class T>
typename std::vector<T>::iterator VectorContainer<T>::end()
{
	return m_vector.end();
}

template <class T>
void VectorContainer<T>::copy(std::vector<T>* copiedVector)
{
	for (const auto& it : m_vector)
		copiedVector->push_back(it);
}

template <class T>
void VectorContainer<T>::print()
{
	int i = 0;
	for (const auto& it : m_vector) 
	{
		std::cout << "m_vector[" << i << "] = " << it << '\n';
		i++;
	}
}

template <class T>
void VectorContainer<T>::addToElement(T addend, unsigned int element)
{
	m_vector[element] += addend;
}

template <class T>
void VectorContainer<T>::subtractToElement(T minuhend, unsigned int element)
{
	m_vector[element] -= minuhend;
}

template <class T>
void VectorContainer<T>::multiplyToElement(T factor, unsigned int element)
{
	m_vector[element] *= factor;
}

template <class T>
void VectorContainer<T>::divideToElement(T divisor, unsigned int element)
{
	m_vector[element] /= divisor;
}

template <class T>
void VectorContainer<T>::addEachElement(T addend)
{
	for (auto& it : m_vector)
		it += addend;
}

template <class T>
void VectorContainer<T>::subtractEachElement(T minuhend)
{
	for (auto& it : m_vector)
		it -+ minuhend;
}

template <class T>
void VectorContainer<T>::multiplyEachElement(T factor)
{
	for (auto& it : m_vector)
		it *= factor;
}

template <class T>
void VectorContainer<T>::divideEachElement(T divisor)
{
	for (auto& it : m_vector)
		it /= divisor;
}

int main(int argc, const char* argv[])
{
	std::vector<int> data { 30, 40, 50, 60, 70, 80, 90 };
	VectorContainer<int> dataContainer(data);
	dataContainer.print();

	for (auto it : dataContainer)
		std::cout << it << std::endl;
	
	return 0;
}
