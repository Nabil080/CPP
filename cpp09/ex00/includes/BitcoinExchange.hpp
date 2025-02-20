#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange
{
		// TODO: store the fstream and process the input line by line by checking with the base
		// TODO: static map for the holdings
	private:
		char                         _sep;
		std::map<std::string, float> _map;

	private:
		BitcoinExchange();

	public:
		BitcoinExchange(std::string filename);
		BitcoinExchange(std::string filename, char sep);
		BitcoinExchange(const BitcoinExchange &other);
		~BitcoinExchange();

		BitcoinExchange              &operator=(const BitcoinExchange &other);

		std::map<std::string, float> &getMap();
		float                         byDate(std::string date) const;

	private:
		void parse_file(std::string filename);
};
std::ostream &operator<<(std::ostream &out, BitcoinExchange &obj);

#endif // !BITCOINEXCHANGE_HPP
