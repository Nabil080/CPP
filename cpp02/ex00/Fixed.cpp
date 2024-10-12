#include "Fixed.hpp"
#include <iostream>

const int	fractional_bits = 8;

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->fixed_point_value = 0;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	this->fixed_point_value = other.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->fixed_point_value = other.getRawBits();
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixed_point_value);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->fixed_point_value = raw;
}