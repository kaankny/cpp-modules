#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "❌ WrongAnimal default constructor called" << std::endl;
	this->type = "WrongAnimal";
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "❌ WrongAnimal destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	std::cout << "❌ WrongAnimal copy constructor called" << std::endl;
	this->type = copy.type;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &copy)
{
	std::cout << "❌ WrongAnimal assignation operator called" << std::endl;
	this->type = copy.type;
	return (*this);
}

std::string WrongAnimal::getType() const
{
	return (this->type);
}

void WrongAnimal::makeSound() const
{
	std::cout << "❌ WrongAnimal can't make sound" << std::endl;
}
