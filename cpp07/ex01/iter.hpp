#ifndef ITER_HPP
# define ITER_HPP

template <typename T>
void iter(T *array, int length, void (*f)(T const &))
{
	for (int i = 0; i < length; i++)
		f(array[i]);
}

#endif