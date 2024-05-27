#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "🐶 Dog default constructor called" << std::endl;
	this->type = "Dog";
}

Dog::~Dog()
{
	std::cout << "🐶 Dog destructor called" << std::endl;
}

Dog::Dog(const Dog &copy)
{
	std::cout << "🐶 Dog copy constructor called" << std::endl;
	this->type = copy.type;
}

Dog &Dog::operator=(const Dog &copy)
{
	std::cout << "🐶 Dog assignation operator called" << std::endl;
	this->type = copy.type;
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "🐶 Woof Woof" << std::endl;
}
