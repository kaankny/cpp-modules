#include "Span.hpp"

Span::Span() : _n(0), _size(0), _array(NULL) {}

Span::Span(unsigned int n) : _n(n), _size(0), _array(new int[n]) {}

Span::Span(const Span &other) : _n(other._n), _size(other._size), _array(new int[other._n])
{
	for (unsigned int i = 0; i < other._size; i++)
		_array[i] = other._array[i];
}

Span &Span::operator=(const Span &other)
{
	if (this == &other)
		return (*this);
	delete[] _array;
	_n = other._n;
	_size = other._size;
	_array = new int[other._n];
	for (unsigned int i = 0; i < other._size; i++)
		_array[i] = other._array[i];
	return (*this);
}

Span::~Span()
{
	delete[] _array;
}

void Span::addNumber(int n)
{
	if (_size >= _n)
		throw ListFullException();
	_array[_size++] = n;
}

void Span::addNumber(int begin, int end)
{
	if (end < begin)
		throw ListFullException();
	if (_size + end - begin > _n)
		throw ListFullException();
	for (int i = begin; i <= end; i++)
		_array[_size++] = i;
}

int Span::shortestSpan()
{
	if (_size <= 1)
		throw ListEmptyException();
	int min = INT_MAX;
	for (unsigned int i = 0; i < _size; i++)
		for (unsigned int j = i + 1; j < _size; j++)
			if (abs(_array[i] - _array[j]) < min)
				min = abs(_array[i] - _array[j]);
	return (min);
}

int Span::longestSpan()
{
	if (_size <= 1)
		throw ListEmptyException();
	int min = INT_MIN;
	for (unsigned int i = 0; i < _size; i++)
		for (unsigned int j = i + 1; j < _size; j++)
			if (abs(_array[i] - _array[j]) > min)
				min = abs(_array[i] - _array[j]);
	return (min);
}

unsigned int Span::getSize() const
{
	return (_size);
}

unsigned int Span::getN() const
{
	return (_n);
}

int *Span::getArray() const
{
	return (_array);
}

const char *ListFullException::what() const throw()
{
	return ("List is full");
}

const char *ListEmptyException::what() const throw()
{
	return ("List is empty");
}
