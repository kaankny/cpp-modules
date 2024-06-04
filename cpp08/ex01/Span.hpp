#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>

class ListFullException : public std::exception
{
	public:
		virtual const char *what() const throw();
};

class ListEmptyException : public std::exception
{
	public:
		virtual const char *what() const throw();
};

class Span
{
	private:
		unsigned int _n;
		unsigned int _size;
		int *_array;
	public:
		Span();
		Span(unsigned int n);
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span();
		void addNumber(int n);
		void addNumber(int begin, int end);
		int shortestSpan();
		int longestSpan();
		unsigned int getSize() const;
		unsigned int getN() const;
		int *getArray() const;
};

#endif