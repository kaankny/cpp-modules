#include <iostream>
#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Usage: ./btc [filename]" << std::endl;
		return (1);
	}

	BitcoinExchange exchange;

	try
	{
		exchange.readBTCData();
		exchange.processData(av[1]);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
}