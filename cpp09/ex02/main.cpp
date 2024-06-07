#include "PmergeMe.hpp"
#include <ctime>

int main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cout << "Usage: ./PmergeMe [int1] [int2] [int3] ..." << std::endl;
		return (1);
	}

	PmergeMe pmm;
	try
	{
		av++;
		pmm.initList(av);
		pmm.initDeque(av);

		std::cout << "List Before Sort: ";
		for (std::list<int>::iterator it = pmm.getList()->begin(); it != pmm.getList()->end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;

		clock_t start = clock();
		pmm.sort(pmm.getList()->begin(), pmm.getList()->end());
		clock_t end = clock();
		std::cout << "List After Sort: ";
		for (std::list<int>::iterator it = pmm.getList()->begin(); it != pmm.getList()->end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;
		double time2 = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;
		std::cout << "Time taken for list: " << time2 << "μs" << std::endl;
		start = clock();
		pmm.sort(pmm.getDeque()->begin(), pmm.getDeque()->end());
		end = clock();
		double time1 = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;
		std::cout << "Time taken for deque: " << time1 << "μs" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
	return (0);
}