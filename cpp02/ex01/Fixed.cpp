#include "Fixed.hpp"
#include <iostream>
#include <cmath>


Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->fixed_point_value = 0;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::Fixed(const int nbr)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixed_point_value = nbr << (this->fractional_bits);
}

Fixed::Fixed(const float nbr)
{
	std::cout << "Float constructor called" << std::endl;
	this->fixed_point_value = roundf(nbr * (1 << this->fractional_bits));
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->fixed_point_value = other.getRawBits();
	return (*this);
}

std::ostream &operator<<(std::ostream &out, const Fixed &other)
{
	out << other.toFloat();
	return (out);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	return (this->fixed_point_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->fixed_point_value = raw;
}

int	Fixed::toInt(void) const
{
	return (this->fixed_point_value >> this->fractional_bits);
}

float	Fixed::toFloat(void) const
{ 
	return ((float)(this->fixed_point_value) / (1 << this->fractional_bits));
}