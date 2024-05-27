#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main()
{
	Dog *dog = new Dog();
	Cat *cat = new Cat();

	std::cout << "🖥️ Dog brain address: " << dog->getBrain() << std::endl;
	std::cout << "🖥️ Cat brain address: " << cat->getBrain() << std::endl;

	for(int i = 0; i < 3; i++)
	{
		dog->getBrain()->setIdea(i, "🥩 Dog Idea " + std::to_string(i + 1));
		cat->getBrain()->setIdea(i, "🐟 Cat Idea " + std::to_string(i + 1));
	}

	for(int i = 0; i < 3; i++)
		std::cout << "🐾 Dog Idea " << i << ": " << dog->getBrain()->getIdea(i) << std::endl;
	for(int i = 0; i < 3; i++)
		std::cout << "🐾 Cat Idea " << i << ": " << cat->getBrain()->getIdea(i) << std::endl;

	delete dog;
	delete cat;
	return (0);
}
