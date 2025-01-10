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
	static void convert(std::string literal);
};

#endif // !SCALARCONVERTER_HPP
