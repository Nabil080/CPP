#include "Point.hpp"
#include <iostream>

// CONSTRUCTORS

Point::Point(): x(Fixed(0)), y(Fixed(0))
{
	if (this->debug)
		std::cout << "Point Default Constructor called" << std::endl;
}

Point::Point(const float x, const float y): x(Fixed(x)), y(Fixed(y))
{
	if (this->debug)
		std::cout << "Point Float Constructor called" << std::endl;
}


Point::Point(const Point &other): x(other.x), y(other.y)
{
	if (this->debug)
		std::cout << "Point Copy constructor called" << std::endl;
}

Point::Point(const Point &a, const Point &b): x(Fixed(b.getX() - a.getX())), y(Fixed(b.getY() - a.getY()))
{
	if (this->debug)
		std::cout << "Point Vector Constructor called" << std::endl;
}

Point::~Point()
{
	if (this->debug)
		std::cout << "Point Destructor called" << std::endl;
}

// OPERATORS

Point&	Point::operator=(const Point &other)
{
	if (this->debug)
		std::cout << "Point = operator called" << std::endl;
	((Fixed *)&this->x)->setRawBits(other.x.getRawBits());
	((Fixed *)&this->y)->setRawBits(other.y.getRawBits());
	return (*this);
}

std::ostream &operator<<(std::ostream& output, const Point& member)
{
	output << "(" << member.x << "," << member.y << ")";
	return (output);
}

// METHODS

Fixed	Point::getX(void) const
{
	return (this->x);
}

Fixed	Point::getY(void) const
{
	return (this->y);
}

