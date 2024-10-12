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
	print("a < b", a < b);
	print("a <= b", a >= b);
	print("a == b", a == b);
	print("a != b", a != b);
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
	return 0;
}
