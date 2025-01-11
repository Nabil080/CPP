#include "iter.hpp"

int main(void)
{
	char chars[4] = {'a', 'b', 'c', 'd'};
	iter(chars, 4, print);
	std::cout << "\n";

	int ints[6] = {1, 2, 3, 4, 5, 6};
	::iter(ints, 6, print);
	std::cout << "\n";

	std::string strings[2] = {"hello ", "bye"};
	iter<std::string>(strings, 2, print);
	std::cout << "\n";

	return 0;
}
