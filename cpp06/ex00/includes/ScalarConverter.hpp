#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

typedef enum
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	NONE
} t_type;

class ScalarConverter
{
  private:
	ScalarConverter() {};
	~ScalarConverter() {};

  public:
	static int convert(std::string literal);

  private: // helpers
	static t_type getType(std::string literal);
	static void printNumbers(long double converted_number, long double ld_number);
	static void printDouble(double nb, long double ld_number);
	static void printFloat(float nb, long double ld_number);
	static void printInt(int nb, long double ld_number);
	static void printChar(char c, long double ld_number);
};

#endif // !SCALARCONVERTER_HPP
