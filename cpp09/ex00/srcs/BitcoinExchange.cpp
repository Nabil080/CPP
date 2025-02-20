#include "BitcoinExchange.hpp"

#include <cstdlib>
#include <fstream>
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

BitcoinExchange::BitcoinExchange(const char *filename) : _filename(filename)
{
	std::cerr << "[BitcoinExchange filename constructor]" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _filename(other._filename)
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
	if (this == &other)
		return (*this);
	_filename = other._filename;
	return (*this);
}

// methods

void BitcoinExchange::printHoldingsValues() const
{
	std::ifstream infile(_filename);
	if (infile.is_open() == false)
		throw std::runtime_error("Couldn't open " + std::string(_filename));

	std::string buffer;
	t_pair      holding;
	t_pair      exchange_rate;
	float       result;

	std::cerr << std::endl << "----- Calculating holdings value based on exchange rate -----" << std::endl << std::endl;
	while (std::getline(infile, buffer))
	{
		try
		{
			holding = parseLine(buffer, _holdings_separator);
			exchange_rate = findByDate(holding.first);
			result = holding.second * exchange_rate.second;
			std::cout << holding.first << " => " << holding.second << " = " << result << std::endl;
		}
		catch (std::runtime_error &e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}
	std::cerr << std::endl << "----- DONE -----" << std::endl << std::endl;
}

// NOTE: parses the data file inside the static, this function is called only once
BitcoinExchange::t_data BitcoinExchange::getData()
{
	if (_data.empty() == false)
		return (_data);

	std::ifstream infile(_data_filename);
	if (infile.is_open() == false)
		throw std::runtime_error("Couldn't open " + std::string(_data_filename));

	t_data      new_data;
	t_pair      pair;
	std::string buffer;

	std::cerr << std::endl << "----- RETRIEVING DATA FROM " << _data_filename << "-----" << std::endl << std::endl;
	while (std::getline(infile, buffer))
	{
		try
		{
			pair = BitcoinExchange::parseLine(buffer, _data_separator);
			new_data.insert(pair);
		}
		catch (std::exception &e)
		{
			std::cerr << "Error: [" << buffer << "]: " << e.what() << std::endl;
		}
	}
	if (new_data.empty())
		throw(std::runtime_error(std::string(_data_filename) + " is empty."));
	std::cerr << std::endl << "---- DONE ----- " << std::endl << std::endl;

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
		throw(std::runtime_error("No separator: " + line));
	pair.first = line.substr(pos, next_pos - pos);
	pos = next_pos;
	if (!strptime(pair.first.c_str(), "%Y-%m-%d ", &tm))
		throw(std::runtime_error("invalid date"));
	// if not sep, error, else skip sep
	if (line[pos] == ' ')
		next_pos = line.find_first_not_of(' ', pos);
	if (next_pos == std::string::npos || line[next_pos] != sep)
		throw(std::runtime_error("Too many keys: " + line));
	pos = next_pos + 1;
	// skip front space till value, if end error
	next_pos = line.find_first_not_of(' ', pos);
	if (next_pos == std::string::npos)
		throw(std::runtime_error("No value provided: " + line));
	pos = next_pos;
	// store till end of number and check if valid
	next_pos = line.find_first_not_of("0123456789.+-", pos);
	if (next_pos == std::string::npos)
		next_pos = line.size();
	pair.second = std::strtof(line.substr(pos, next_pos - pos).c_str(), NULL);
	if (sep != _data_separator && (next_pos - pos > 4 || pair.second < 0 || 1000 < pair.second))
		throw(std::runtime_error("Invalid value: " + line));
	// skip back spaces, if not end error
	if (line[pos] == ' ')
		next_pos = line.find_first_not_of(' ', pos);
	if (next_pos != line.size() && next_pos != std::string::npos)
		throw(std::runtime_error("Too many values: " + line));

	return (pair);
}

// TODO: fix if data is empty or if there is never a date >= (return last)
BitcoinExchange::t_pair BitcoinExchange::findByDate(std::string date)
{
	t_data           data = getData();
	t_data::iterator it;

	for (it = data.begin(); it != data.end(); it++)
	{
		if (it->first >= date)
			return *(it == data.begin() ? it : it--);
	}
	return (*data.begin());
}
