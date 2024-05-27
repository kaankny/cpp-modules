#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "🐱 Cat default constructor called" << std::endl;
	this->type = "Cat";
}

Cat::~Cat()
{
	std::cout << "🐱 Cat destructor called" << std::endl;
}

Cat::Cat(const Cat &copy)
{
	std::cout << "🐱 Cat copy constructor called" << std::endl;
	this->type = copy.type;
}

Cat &Cat::operator=(const Cat &copy)
{
	std::cout << "🐱 Cat assignation operator called" << std::endl;
	this->type = copy.type;
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "🐱 Meow Meow" << std::endl;
}
