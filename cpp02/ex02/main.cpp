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

int main( void )
{
	Fixed a(10);
	Fixed b(2);

	print("a", a);
	print("b", b);
	std::cout << std::endl;
	print("a + b", a + b);
	print("a - b", a - b);
	print("a * b", a * b);
	print("a / b", a / b);
	std::cout << std::endl;
	print("a > b", a > b);
	print("a >= b", a >= b);
	print("a < b", a < b);
	print("a <= b", a >= b);
	print("a == b", a == b);
	print("a != b", a != b);

	return 0;
}
