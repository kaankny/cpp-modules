#include <iostream>
#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Usage: ./ex01 [string]" << std::endl;
		return (1);
	}
	RPN rpn;
	try
	{
		rpn.initStack(av[1]);
		rpn.execute();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}