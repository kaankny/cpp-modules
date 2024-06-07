#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	*this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	this->_list = other._list;
	this->_deque = other._deque;
	return (*this);
}

std::list<int> *PmergeMe::getList()
{
	return (&_list);
}

std::deque<int> *PmergeMe::getDeque()
{
	return (&_deque);
}

void PmergeMe::initList(char **av)
{
	while (*av)
	{
		_list.push_back(std::atoi(*av));
		av++;
	}
}

void PmergeMe::initDeque(char **av)
{
	while (*av)
	{
		_deque.push_back(std::atoi(*av));
		av++;
	}
}

void PmergeMe::sort(std::deque<int>::iterator first, std::deque<int>::iterator last)
{
	size_t distance = std::distance(first, last);
	if (distance < 16)
	{
		insertionSort(first, last);
		return;
	}
	else
	{
		std::deque<int>::iterator middle = first + distance / 2;
		sort(first, middle);
		sort(middle, last);
		merge(first, middle, last);
	}
}

void PmergeMe::insertionSort(std::deque<int>::iterator first, std::deque<int>::iterator last)
{
	for (std::deque<int>::iterator i = first + 1; i != last; i++)
	{
		std::deque<int>::iterator::value_type key = *i;
		std::deque<int>::iterator j = i - 1;
		while (j >= first && *j > key)
		{
			*(j + 1) = *j;
			--j;
		}
		*(j + 1) = key;
	}
}

void PmergeMe::merge(std::deque<int>::iterator first, std::deque<int>::iterator middle, std::deque<int>::iterator last)
{
	std::deque<int> left(first, middle);
	std::deque<int> right(middle, last);

	std::deque<int>::iterator leftIt = left.begin();
	std::deque<int>::iterator rightIt = right.begin();
	std::deque<int>::iterator it = first;

	while (leftIt != left.end() && rightIt != right.end())
	{
		if (*leftIt < *rightIt)
		{
			*it = *leftIt;
			++leftIt;
		}
		else
		{
			*it = *rightIt;
			++rightIt;
		}
		++it;
	}

	while (leftIt != left.end())
	{
		*it = *leftIt;
		++leftIt;
		++it;
	}

	while (rightIt != right.end())
	{
		*it = *rightIt;
		++rightIt;
		++it;
	}

}

void PmergeMe::sort(std::list<int>::iterator first, std::list<int>::iterator last)
{
	size_t distance = std::distance(first, last);
	if (distance < 16)
	{
		insertionSort(first, last);
		return;
	}
	else
	{
		std::list<int>::iterator middle = first;
		std::advance(middle, distance / 2);
		sort(first, middle);
		sort(middle, last);
		merge(first, middle, last);
	}
}

void PmergeMe::insertionSort(std::list<int>::iterator first, std::list<int>::iterator last)
{
	for (std::list<int>::iterator i = first; i != last; i++)
	{
		std::list<int>::iterator::value_type key = *i;
		std::list<int>::iterator j = i; 
		while (j != first && *std::prev(j) > key)
		{
			*j = *std::prev(j);
			--j;
		}
		*j = key;
	}
}

void PmergeMe::merge(std::list<int>::iterator first, std::list<int>::iterator middle, std::list<int>::iterator last)
{
	std::list<int> left(first, middle);
	std::list<int> right(middle, last);

	std::list<int>::iterator leftIt = left.begin();
	std::list<int>::iterator rightIt = right.begin();
	std::list<int>::iterator it = first;

	while (leftIt != left.end() && rightIt != right.end())
	{
		if (*leftIt < *rightIt)
		{
			*it = *leftIt;
			++leftIt;
		}
		else
		{
			*it = *rightIt;
			++rightIt;
		}
		++it;
	}

	while (leftIt != left.end())
	{
		*it = *leftIt;
		++leftIt;
		++it;
	}

	while (rightIt != right.end())
	{
		*it = *rightIt;
		++rightIt;
		++it;
	}
}