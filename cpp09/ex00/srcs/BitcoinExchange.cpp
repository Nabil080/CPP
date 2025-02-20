#include "BitcoinExchange.hpp"

#include <cstdlib>
#include <iostream>

const char                   *BitcoinExchange::_data_filename = "data.csv";
const char                    BitcoinExchange::_data_separator = ',';
const char                    BitcoinExchange::_holdings_separator = '|';
const BitcoinExchange::t_data BitcoinExchange::_data = BitcoinExchange::getData();

// constructors

BitcoinExchange::BitcoinExchange()
{
	std::cerr << "[BitcoinExchange default constructor] /!\\ This should never be called !!" << std::endl;
}

BitcoinExchange::BitcoinExchange(const char *filename) : _filename(filename), _holdings_file(filename)
{
	std::cerr << "[BitcoinExchange filename constructor]" << std::endl;
	if (_holdings_file.is_open() == false)
		throw std::runtime_error("Couldn't open " + std::string(filename));
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _filename(other._filename), _holdings_file(_filename)
{
	std::cerr << "[BitcoinExchange copy constructor]" << std::endl;
	if (_holdings_file.is_open() == false)
		throw std::runtime_error("Couldn't open " + std::string(_filename));
}

BitcoinExchange::~BitcoinExchange()
{
	std::cerr << "[BitcoinExchange destructor]" << std::endl;
}

// operators

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this == &other)
		return (*this);
	_filename = other._filename;
	_holdings_file.open(_filename);
	if (_holdings_file.is_open() == false)
		throw std::runtime_error("Couldn't open " + std::string(_filename));
	return (*this);
}

// methods

// NOTE: parses the data file inside the static, this function is called only once
BitcoinExchange::t_data BitcoinExchange::getData()
{
	if (_data.empty() == false)
		return (_data);

	std::fstream infile(_data_filename);
	if (infile.is_open() == false)
		throw std::runtime_error("Couldn't open " + std::string(_data_filename));

	t_data      new_data;
	t_pair      pair;
	std::string buffer;
	while (std::getline(infile, buffer))
	{
		try
		{
			pair = BitcoinExchange::parseLine(buffer, _data_separator);
			new_data.insert(pair);
		}
		catch (std::exception &e)
		{
			// std::cout << "Invalid line inside " << _data_filename << ": " << buffer << std::endl;
			std::cout << buffer << ": " << e.what() << std::endl;
		}
	}
	t_data::iterator it;
	for (it = new_data.begin(); it != new_data.end(); it++)
		std::cout << "[" << it->first << "]:" << it->second << std::endl;

	return (new_data);
}

BitcoinExchange::t_pair BitcoinExchange::parseLine(std::string line, char sep = _holdings_separator)
{
	t_pair    pair;
	size_t    pos = 0;
	size_t    next_pos = line.find_first_not_of(' ', pos);
	struct tm tm;

	// skip front spaces
	if (next_pos != std::string::npos)
		pos = next_pos;
	// store till next space or sep, if not a date > error
	next_pos = line.find_first_of(std::string(" ") + sep, pos);
	if (next_pos == std::string::npos)
		throw(std::runtime_error("No separator"));
	pair.first = line.substr(pos, next_pos - pos);
	pos = next_pos;
	if (!strptime(pair.first.c_str(), "%Y-%m-%d ", &tm))
		throw(std::runtime_error("invalid date"));
	// if not sep, error, else skip sep
	if (line[pos] == ' ')
		next_pos = line.find_first_not_of(' ', pos);
	if (next_pos == std::string::npos || line[next_pos] != sep)
		throw(std::runtime_error("Too many keys"));
	pos = next_pos + 1;
	// skip space
	next_pos = line.find_first_not_of(' ', pos);
	if (next_pos == std::string::npos)
		throw(std::runtime_error("No value provided"));
	pos = next_pos;
	// store till next space, if size > 4 error
	next_pos = line.find_first_not_of("0123456789.", pos);
	if (next_pos == std::string::npos)
		next_pos = line.size();
	// TODO: check value format and max if holdings
	pair.second = std::strtof(line.substr(pos, next_pos - pos).c_str(), NULL);
	if (sep != _data_separator && (next_pos - pos > 4 || pair.second < 0 || 1000 < pair.second))
		throw(std::runtime_error("Invalid value"));
	// skip spaces, if not end error
	if (line[pos] == ' ')
		next_pos = line.find_first_not_of(' ', pos);
	if (next_pos != line.size() && next_pos != std::string::npos)
		throw(std::runtime_error("Too many values"));

	return (pair);
}
