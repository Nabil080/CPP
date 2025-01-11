#ifndef DATA_HPP
#define DATA_HPP

#include <ostream>
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

std::ostream &operator<<(std::ostream &out, const Data &obj);

#endif // !DATA_HPP
