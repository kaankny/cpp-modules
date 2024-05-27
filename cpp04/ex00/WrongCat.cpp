#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "❌ WrongCat default constructor called" << std::endl;
	this->type = "WrongCat";
}

WrongCat::~WrongCat()
{
	std::cout << "❌ WrongCat destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy)
{
	std::cout << "❌ WrongCat copy constructor called" << std::endl;
	this->type = copy.type;
}

WrongCat &WrongCat::operator=(const WrongCat &copy)
{
	std::cout << "❌ WrongCat assignation operator called" << std::endl;
	this->type = copy.type;
	return (*this);
}

void WrongCat::makeSound() const
{
	std::cout << "🐱 Meow Meow" << std::endl;
}
