#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: Invalid number of arguments" << std::endl;
		return 1;
	}
	ScalarConverter converter;
	converter.convert(argv[1]);
	return 0;
}