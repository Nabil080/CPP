#include <iostream>
#include "Fixed.hpp"
#include <bitset>

int main( void ) {
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );

	a = Fixed( 1234.4321f );

	std::cout << std::endl;
	std::cout << "a is " << a.getRawBits() << "\t\t(1234.4321)" << std::endl;
	std::cout << "b is " << b.getRawBits() << "\t\t(10)" << std::endl;
	std::cout << "c is " << c.getRawBits() << "\t\t(42.42)" << std::endl;
	std::cout << "d is " << d.getRawBits() << "\t\t(10)" << std::endl;
	std::cout << std::endl;
	std::cout << "a is " << a << " as float\t(" << std::bitset<32>(a.getRawBits()) << ")" << std::endl;
	std::cout << "b is " << b << " as float\t(" << std::bitset<32>(b.getRawBits()) << ")" << std::endl;
	std::cout << "c is " << c << " as float\t(" << std::bitset<32>(c.getRawBits()) << ")" << std::endl;
	std::cout << "d is " << d << " as float\t(" << std::bitset<32>(d.getRawBits()) << ")" << std::endl;
	std::cout << std::endl;
	std::cout << "a is " << a.toInt() << " as integer\t(" << std::bitset<32>(a.toInt()) << ")" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer\t(" << std::bitset<32>(b.toInt()) << ")" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer\t(" << std::bitset<32>(c.toInt()) << ")" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer\t(" << std::bitset<32>(d.toInt()) << ")" << std::endl;
	std::cout << std::endl;
	return 0;
}