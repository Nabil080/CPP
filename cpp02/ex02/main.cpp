#include <iostream>
#include "Fixed.hpp"
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
	Fixed a(10);
	Fixed b(2);
	Fixed c(2.5f);

	print("a", a);
	print("b", b);
	sep("Arithmetic operators");
	print("a + b", (a + b));
	print("a - b", (a - b));
	print("a * b", (a * b));
	print("a / b", (a / b));
	sep("Comparison operators");
	print("a > b", a > b);
	print("a >= b", a >= b);
	print("a >= 10", a >= 10);
	print("a < b", a < b);
	print("a <= b", a <= b);
	print("a <= 10", a <= 10);
	print("a == b", a == b);
	print("a == 10", a == 10);
	print("a != b", a != b);
	print("a != 10", a != 10);
	sep("With a float");
	print("c", c);
	print("a + c", a + c);
	print("a * c", a * c);
	print("a / c", a / c);
	sep("Increment / Decrement");
	print("++a", ++a);
	print("a++", a++);
	print("a", a);
	print("--a", --a);
	print("a--", a--);
	print("a", a);
	sep("Member functions");
	print("min(a, b)", Fixed::min(a, b));
	print("max(a, b)", Fixed::max(a, b));
	return 0;
}
