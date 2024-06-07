#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <list>
#include <deque>

class PmergeMe
{
	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);

		void initList(char **av);
		void initDeque(char **av);

		void sort(std::deque<int>::iterator first, std::deque<int>::iterator last);
		void sort(std::list<int>::iterator first, std::list<int>::iterator last);

		std::list<int> *getList();
		std::deque<int> *getDeque();

	private:
		std::deque<int> _deque;
		std::list<int> _list;

		void insertionSort(std::deque<int>::iterator first, std::deque<int>::iterator last);
		void insertionSort(std::list<int>::iterator first, std::list<int>::iterator last);
		void merge(std::deque<int>::iterator first, std::deque<int>::iterator middle, std::deque<int>::iterator last);
		void merge(std::list<int>::iterator first, std::list<int>::iterator middle, std::list<int>::iterator last);

};

#endif