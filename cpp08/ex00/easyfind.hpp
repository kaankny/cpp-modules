#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>

class NotFoundExpection : public std::exception
{
	virtual const char* what() const throw() {
		return "Element not found";
	}
};

template <typename T>
typename T::iterator easyfind(T &container, int n)
{
	typename T::iterator find = std::find(container.begin(), container.end(), n);
	if (find == container.end())
		throw NotFoundExpection();
	return (find);
}

#endif