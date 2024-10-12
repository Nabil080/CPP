#include "Fixed.hpp"
#include <iostream>
#include <cmath>

// ---------- CONSTRUCTORS ----------

Fixed::Fixed(void)
{
	if (DEBUG)
		std::cout << "Default constructor called" << std::endl;
	this->fixed_point_value = 0;
}

Fixed::Fixed(const Fixed &other)
{
	if (DEBUG)
		std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::Fixed(const int nbr)
{
	if (DEBUG)
		std::cout << "Int constructor called" << std::endl;
	this->fixed_point_value = nbr << (this->fractional_bits);
}

Fixed::Fixed(const float nbr)
{
	if (DEBUG)
		std::cout << "Float constructor called" << std::endl;
	this->fixed_point_value = roundf(nbr * (1 << this->fractional_bits));
}

Fixed::~Fixed(void)
{
	if (DEBUG)
		std::cout << "Destructor called" << std::endl;
}

// ---------- OPERATORS ----------

// ------- copy -------

Fixed &Fixed::operator=(const Fixed &other)
{
	if (DEBUG)
		std::cout << "Copy assignment operator called" << std::endl;
	this->fixed_point_value = other.fixed_point_value;
	return (*this);
}

// ------- arithmetic -------

Fixed	Fixed::operator+(const Fixed& other)
{
	return (Fixed(this->fixed_point_value + other.fixed_point_value));
}

Fixed	Fixed::operator-(const Fixed& other)
{
	return (Fixed(this->fixed_point_value - other.fixed_point_value));
}

Fixed	Fixed::operator*(const Fixed& other)
{
	Fixed	result;

	result.fixed_point_value = ((long)this->fixed_point_value * (long)other.fixed_point_value) / (1 << this->fractional_bits);
	return (result);
}

Fixed	Fixed::operator/(const Fixed& other)
{
	return (Fixed(this->fixed_point_value / other.fixed_point_value));
}

// ------- comparison -------

bool	Fixed::operator<(const Fixed &other)
{
	return (this->fixed_point_value < other.fixed_point_value);
}

bool	Fixed::operator<=(const Fixed &other)
{
	return (this->fixed_point_value <= other.fixed_point_value);
}

bool	Fixed::operator>(const Fixed &other)
{
	return (this->fixed_point_value > other.fixed_point_value);
}

bool	Fixed::operator>=(const Fixed &other)
{
	return (this->fixed_point_value >= other.fixed_point_value);
}

bool	Fixed::operator==(const Fixed &other)
{
	return (this->fixed_point_value == other.fixed_point_value);
}

bool	Fixed::operator!=(const Fixed &other)
{
	return (this->fixed_point_value != other.fixed_point_value);
}

// ------- increment/decrement -------

Fixed	Fixed::operator++()
{
	this->fixed_point_value++;
	return (*this);
}

// ------- input/output -------

std::ostream &operator<<(std::ostream &out, const Fixed &other)
{
	out << other.toFloat();
	return (out);
}

// ---------- METHODS ----------

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