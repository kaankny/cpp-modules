#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "🐾 Animal default constructor called" << std::endl;
	this->type = "Animal";
}

Animal::~Animal()
{
	std::cout << "🐾 Animal destructor called" << std::endl;
}

Animal::Animal(const Animal &copy)
{
	std::cout << "🐾 Animal copy constructor called" << std::endl;
	this->type = copy.type;
}

Animal &Animal::operator=(const Animal &copy)
{
	std::cout << "🐾 Animal assignation operator called" << std::endl;
	this->type = copy.type;
	return (*this);
}

std::string Animal::getType() const
{
	return (this->type);
}
