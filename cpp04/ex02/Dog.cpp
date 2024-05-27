#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "🐶 Dog default constructor called" << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
}

Dog::~Dog()
{
	delete this->brain;
	std::cout << "🐶 Dog destructor called" << std::endl;
}

Dog::Dog(const Dog &copy)
{
	std::cout << "🐶 Dog copy constructor called" << std::endl;
	this->type = copy.type;
	this->brain = new Brain(*copy.brain);
}

Dog &Dog::operator=(const Dog &copy)
{
	std::cout << "🐶 Dog assignation operator called" << std::endl;
	this->type = copy.type;
	delete this->brain;
	this->brain = new Brain(*copy.brain);
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "🐶 Woof Woof" << std::endl;
}

Brain *Dog::getBrain() const
{
	return (this->brain);
}
