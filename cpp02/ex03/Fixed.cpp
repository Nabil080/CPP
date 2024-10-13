#include "Fixed.hpp"
#include <iostream>
#include <cmath>

// ---------- CONSTRUCTORS ----------

Fixed::Fixed(void)
{
	if (this->debug)
		std::cout << "Fixed Default constructor called" << std::endl;
	this->fixed_point_value = 0;
}

Fixed::Fixed(const Fixed &other)
{
	if (this->debug)
		std::cout << "Fixed Copy constructor called" << std::endl;
	this->fixed_point_value = other.fixed_point_value;
}

Fixed::Fixed(const int nbr)
{
	if (this->debug)
		std::cout << "Fixed Int constructor called" << std::endl;
	this->fixed_point_value = nbr << (this->fractional_bits);
}

Fixed::Fixed(const float nbr)
{
	if (this->debug)
		std::cout << "Fixed Float constructor called" << std::endl;
	this->fixed_point_value = roundf(nbr * (1 << this->fractional_bits));
}

Fixed::~Fixed(void)
{
	if (this->debug)
		std::cout << "Fixed Destructor called" << std::endl;
}

// ---------- OPERATORS ----------

// ------- copy -------

Fixed &Fixed::operator=(const Fixed &other)
{
	if (this->debug)
		std::cout << "Fixed Copy assignment operator called" << std::endl;
	this->fixed_point_value = other.fixed_point_value;
	return (*this);
}

// ------- arithmetic -------

Fixed Fixed::operator+(const Fixed &other)
{
	Fixed result;

	result.fixed_point_value = this->fixed_point_value + other.fixed_point_value;
	return (result);
}

Fixed Fixed::operator-(const Fixed &other)
{
	Fixed result;

	result.fixed_point_value = this->fixed_point_value - other.fixed_point_value;
	return (result);
}

Fixed Fixed::operator*(const Fixed &other)
{
	Fixed result;

	result.fixed_point_value = ((long)this->fixed_point_value * (long)other.fixed_point_value) / (1 << this->fractional_bits);
	return (result);
}

Fixed Fixed::operator/(const Fixed &other)
{
	return (Fixed(this->fixed_point_value / other.fixed_point_value));
}

// ------- comparison -------

bool Fixed::operator<(const Fixed &other) const
{
	return (this->fixed_point_value < other.fixed_point_value);
}

bool Fixed::operator<=(const Fixed &other) const
{
	return (this->fixed_point_value <= other.fixed_point_value);
}

bool Fixed::operator>(const Fixed &other) const
{
	return (this->fixed_point_value > other.fixed_point_value);
}

bool Fixed::operator>=(const Fixed &other) const
{
	return (this->fixed_point_value >= other.fixed_point_value);
}

bool Fixed::operator==(const Fixed &other) const
{
	return (this->fixed_point_value == other.fixed_point_value);
}

bool Fixed::operator!=(const Fixed &other) const
{
	return (this->fixed_point_value != other.fixed_point_value);
}

// ------- increment/decrement -------

Fixed Fixed::operator++()
{
	this->fixed_point_value++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp = *this;
	this->fixed_point_value++;
	return (tmp);
}

Fixed Fixed::operator--()
{
	this->fixed_point_value--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp = *this;
	this->fixed_point_value--;
	return (tmp);
}

// ------- input/output -------

std::ostream &operator<<(std::ostream &out, const Fixed &other)
{
	out << other.toFloat();
	return (out);
}

// ---------- METHODS ----------

int Fixed::getRawBits(void) const
{
	return (this->fixed_point_value);
}

void Fixed::setRawBits(int const raw)
{
	this->fixed_point_value = raw;
}

int Fixed::toInt(void) const
{
	return (this->fixed_point_value >> this->fractional_bits);
}

float Fixed::toFloat(void) const
{
	return ((float)(this->fixed_point_value) / (1 << this->fractional_bits));
}

// ------- static functions -------

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}
