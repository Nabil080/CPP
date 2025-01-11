#ifndef DATA_HPP
#define DATA_HPP

#include <string>

class Data
{
  public:
	Data();
	Data(const Data &);
	Data &operator=(const Data &);
	~Data();

  public:
	std::string name;
	int number;
	bool boolean;
};

#endif // !DATA_HPP
