#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "🐱 Cat default constructor called" << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
}

Cat::~Cat()
{
	delete this->brain;
	std::cout << "🐱 Cat destructor called" << std::endl;
}

Cat::Cat(const Cat &copy)
{
	std::cout << "🐱 Cat copy constructor called" << std::endl;
	this->type = copy.type;
	this->brain = new Brain(*copy.brain);	
}

Cat &Cat::operator=(const Cat &copy)
{
	std::cout << "🐱 Cat assignation operator called" << std::endl;
	this->type = copy.type;
	delete this->brain;
	this->brain = new Brain(*copy.brain);
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "🐱 Meow Meow" << std::endl;
}

Brain *Cat::getBrain() const
{
	return (this->brain);
}
