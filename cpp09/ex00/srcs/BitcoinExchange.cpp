#include "BitcoinExchange.hpp"

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>
#include <stdexcept>

// constructors

BitcoinExchange::BitcoinExchange()
{
	std::cerr << "[BitcoinExchange default constructor] /!\\ This should never be called !!" << std::endl;
}

BitcoinExchange::BitcoinExchange(std::string filename) : _sep('|')
{
	std::cerr << "[BitcoinExchange filename constructor]" << std::endl;
	parse_file(filename);
}

BitcoinExchange::BitcoinExchange(std::string filename, char sep) : _sep(sep)
{
	std::cerr << "[BitcoinExchange filename and sep constructor]" << std::endl;
	parse_file(filename);
}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _sep(other._sep), _map(other._map)
{
	std::cerr << "[BitcoinExchange copy constructor]" << std::endl;
}

BitcoinExchange::~BitcoinExchange()
{
	std::cerr << "[BitcoinExchange destructor]" << std::endl;
}

// operators

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	_map = other._map;
	return (*this);
}

std::ostream &operator<<(std::ostream &out, BitcoinExchange &obj)
{
	for (std::map<std::string, float>::iterator it = obj.getMap().begin(); it != obj.getMap().end(); it++)
		out << "[Date]: " << (*it).first << "|[Value]: " << (*it).second << std::endl;
	return (out);
}

// methods

std::map<std::string, float> &BitcoinExchange::getMap()
{
	return (_map);
}
float BitcoinExchange::byDate(std::string date) const
{
	std::map<std::string, float>::const_iterator it = _map.find(date);
	if (it == _map.end())
		throw std::length_error("invalid date /!\\ CHANGE THIS MESSAGE");
	return (_map.at(0));
}

void BitcoinExchange::parse_file(std::string filename)
{
	std::fstream infile(filename.c_str());
	if (infile.is_open() == false)
		throw std::runtime_error("Couldn't open " + filename);

	std::string buffer;
	std::string date;
	float       value;
	size_t      sep_pos;

	int         i = 0;
	while (getline(infile, buffer))
	{
		// find the separator
		sep_pos = buffer.find(_sep);
		// check that there is a date before
		date = buffer.substr(0, sep_pos);
		// check that there is a value after
		value = i++;
		// store both
		_map.insert(std::make_pair(date, value));
	}
}
