#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>
#include "Data.hpp"

class Serializer
{
	public:
		Serializer();
		~Serializer();
		Serializer(const Serializer &src);
		Serializer &operator=(const Serializer &src);

		uintptr_t serialize(Data *ptr);
		Data *deserialize(uintptr_t raw);
};

#endif