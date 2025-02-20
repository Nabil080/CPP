#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

// TODO: store the fstream and process the input line by line by checking with the base
class BitcoinExchange
{
	public:
		typedef std::map<std::string, float>  t_data;
		typedef std::pair<std::string, float> t_pair;

	private:
		static const t_data _data;
		static const char  *_data_filename;
		static const char   _data_separator;
		static const char   _holdings_separator;
		const char         *_filename;

	private:
		BitcoinExchange();

	public:
		BitcoinExchange(const char *filename);
		BitcoinExchange(const BitcoinExchange &other);
		~BitcoinExchange();

		BitcoinExchange &operator=(const BitcoinExchange &other);

		void             printHoldingsValues() const;

		static t_data    getData();
		static t_pair    parseLine(std::string line, char sep);
};

#endif // !BITCOINEXCHANGE_HPP
