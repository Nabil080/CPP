#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <class T> class MutantStack : public std::stack<T>
{
	public:
		MutantStack() { std::cerr << "[MutantStack default constructor]" << std::endl; }
		MutantStack(const MutantStack &other) : std::stack<T>(other)
		{
			std::cerr << "[MutantStack copy constructor]" << std::endl;
		}
		~MutantStack() { std::cerr << "[MutantStack destructor]" << std::endl; }

		MutantStack &operator=(const MutantStack &other)
		{
			if (this != other)
				return (*this);
			return (*this);
		}

		typedef typename std::stack<T>::container_type::iterator               iterator;
		typedef typename std::stack<T>::container_type::const_iterator         const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator       reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

	public:
		iterator               begin() { return this->c.begin(); }
		iterator               end() { return this->c.end(); }

		const_iterator         begin() const { return this->c.begin(); }

		const_iterator         end() const { return this->c.end(); }

		reverse_iterator       rbegin() { return this->c.rbegin(); }

		reverse_iterator       rend() { return this->c.rend(); }

		const_reverse_iterator rbegin() const { return this->c.rbegin(); }

		const_reverse_iterator rend() const { return this->c.rend(); }
};

#endif // !MUTANTSTACK_HPP
