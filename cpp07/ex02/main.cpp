#include "Array.hpp"
#include <iostream>

int main(void)
{
	Array<int> a(5);
	Array<int> b(5);

	for (unsigned int i = 0; i < a.size(); i++)
		a[i] = i;
	for (unsigned int i = 0; i < b.size(); i++)
		b[i] = i + 5;

	std::cout << "a: ";
	for (unsigned int i = 0; i < a.size(); i++)
		std::cout << a[i] << " ";
	std::cout << std::endl;

	std::cout << "b: ";
	for (unsigned int i = 0; i < b.size(); i++)
		std::cout << b[i] << " ";
	std::cout << std::endl;

	Array<int> c(a);

	std::cout << "c: ";
	for (unsigned int i = 0; i < c.size(); i++)
		std::cout << c[i] << " ";
	std::cout << std::endl;

	Array<int> d;

	d = b;

	std::cout << "d: ";
	for (unsigned int i = 0; i < d.size(); i++)
		std::cout << d[i] << " ";
	std::cout << std::endl;

	try
	{
		std::cout << "a[5]: " << a[5] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
