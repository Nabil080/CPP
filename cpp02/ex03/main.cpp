#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"
#include <bitset>

void	print(std::string name, Fixed val)
{
	std::cout << name << " = " << val << std::endl;
}

void	print(std::string name, bool val)
{
	if (val)
		std::cout << name << " is true" << std::endl;
	else
		std::cout << name << " is false" << std::endl;
}

void	sep(std::string str)
{
	std::cout << std::endl << "-----" << str << "-----" << std::endl;
}

int main( void )
{
	Point	a;
	a.print();
	Point	b(10, 10);
	b.print();
	Point	c(b);
	c.print();

	c = a;
	c.print();

	return 0;
}
