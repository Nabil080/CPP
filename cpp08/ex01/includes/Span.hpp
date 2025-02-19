#ifndef SPAN_HPP
#define SPAN_HPP

#include <ostream>
#include <vector>

class Span
{
	private:
		unsigned int     _capacity;
		std::vector<int> _values;

	public:
		Span();
		Span(unsigned int capacity);
		Span(const Span &other);
		~Span();

		Span                      &operator=(const Span &other);

		unsigned int               getCapacity() const;
		const std::vector<int>    &getValues() const;

		void                       addNumber(int number);
		unsigned int               shortestSpan() const;
		unsigned int               longestSpan() const;
		template <typename T> void fill(T begin, T end)
		{
			while (begin != end)
				addNumber(*begin++);
		}
};
std::ostream &operator<<(std::ostream &out, const Span &obj);

#endif
