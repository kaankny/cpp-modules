#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "🧠 Brain default constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "🧠 Brain destructor called" << std::endl;
}

Brain::Brain(const Brain &copy)
{
	std::cout << "🧠 Brain copy constructor called" << std::endl;
	int i = 0;
	while (i < 100)
	{
		this->ideas[i] = copy.ideas[i];
		i++;
	}
}

Brain &Brain::operator=(const Brain &copy)
{
	std::cout << "🧠 Brain assignation operator called" << std::endl;
	int i = 0;
	while (i < 100)
	{
		this->ideas[i] = copy.ideas[i];
		i++;
	}
	return (*this);
}

void Brain::setIdea(int index, std::string idea)
{
	this->ideas[index] = idea;
}

std::string Brain::getIdea(int index) const
{
	return (this->ideas[index]);
}
