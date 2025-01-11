#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
template <typename T> class Array
{
  private:
	unsigned int len;
	T *data;

  public:
	Array() : len(0), data(new T[0]) {};
	Array(unsigned int n) : len(n), data(new T[n]) {};
	Array(const Array &other) : len(other.len), data(new T[other.len])
	{
		for (unsigned int i = 0; i < other.len; i++)
			this->data[i] = other.data[i];
	}
	~Array()
	{
		delete[] this->data;
	}

	T &operator=(const Array &other)
	{
		if (this == &other)
			return (*this);
		this->len = other.len;
		delete[] this->data;
		this->data = new T[other.len];
		for (unsigned int i = 0; i < other.len; i++)
			this->data[i] = other.data[i];
		return (*this);
	}

	T &operator[](unsigned int index)
	{
		if (index >= this->len)
			throw std::exception();
		return (this->data[index]);
	}

	unsigned int size() const
	{
		return this->size;
	}
};

#endif
