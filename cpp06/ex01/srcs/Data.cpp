#include "Data.hpp"

Data::Data() : name("default"), number(0), boolean(false)
{
	;
}

Data::Data(const Data &other) : name(other.name), number(other.number), boolean(other.boolean)
{
	;
}

Data::~Data()
{
	;
}

Data &Data::operator=(const Data &other)
{
	this->name = other.name;
	this->number = other.number;
	this->boolean = other.boolean;
	return (*this);
}
