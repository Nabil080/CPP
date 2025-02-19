#ifndef SPAN_HPP
#define SPAN_HPP

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

		void                       addNumber(int number);
		unsigned int               shortestSpan();
		unsigned int               longestSpan();
		template <typename T> void fill(T begin, T end)
		{
			while (begin != end)
				addNumber(*begin++);
		}
};

#endif
