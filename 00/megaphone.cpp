#include <iostream>
#include <string>

int main(int argc, char **argv)
{
	std::size_t	i;

	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	argv++;
	while (*argv)
	{
		i = 0;
		while ((*argv)[i])
			std::cout << (char)toupper((*argv)[i++]);
		argv++;
	}
	std::cout << std::endl;
	return (0);
}
