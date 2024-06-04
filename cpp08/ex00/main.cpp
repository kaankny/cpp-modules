#include <iostream>
#include "easyfind.hpp"
#include <vector>

int main() {
	std::vector<int> vec;
	for (int i = 0; i < 10; i++)
		vec.push_back(i);
	try
	{
		std::cout << *easyfind(vec, 5) << std::endl;
		std::cout << *easyfind(vec, 10) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}