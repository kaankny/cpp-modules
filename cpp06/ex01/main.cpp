#include "Serializer.hpp"
#include <iostream>
#include "Data.hpp"

int main()
{
	Serializer serializer;
	Data data;
	data.name = "Kaan";
	data.last_name = "KANYILMAZ";
	data.age = 13;

	uintptr_t serialized = serializer.serialize(&data);
	Data *deserialized = serializer.deserialize(serialized);

	std::cout << "Name: " << deserialized->name << std::endl;
	std::cout << "Last name: " << deserialized->last_name << std::endl;
	std::cout << "Age: " << deserialized->age << std::endl;

	return (0);
}