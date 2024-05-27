#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main()
{
	Animal **animals = new Animal*[4];
	for(int i = 0; i < 4; i++)
	{
		if (i % 2 == 0)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	for(int i = 0; i < 4; i++)
		animals[i]->makeSound();

	for(int i = 0; i < 4; i++)
		delete animals[i];
	delete [] animals;

	Dog *dog1 = new Dog();
	Dog *dog2 = new Dog(*dog1);
	Dog *dog3 = new Dog();
	*dog3 = *dog1;

	std::cout << "🖥️ Dog1 Memory Address: " << dog1 << ", Brain Memory Address: " << dog1->getBrain() << std::endl;
	std::cout << "🖥️ Dog2 Memory Address: " << dog2 << ", Brain Memory Address: " << dog2->getBrain() << std::endl;
	std::cout << "🖥️ Dog3 Memory Address: " << dog3 << ", Brain Memory Address: " << dog3->getBrain() << std::endl;
	
	delete dog1;
	delete dog2;
	delete dog3;
	return (0);
}