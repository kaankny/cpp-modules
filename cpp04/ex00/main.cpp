#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
	const Animal *meta = new Animal();
	const Animal *dog = new Dog();
	const Animal *cat = new Cat();
	const WrongAnimal *wrongMeta = new WrongAnimal();
	const WrongAnimal *wrongCat = new WrongCat();

	std::cout << "----------------------------------" << std::endl;
	std::cout << "🐾 Animal" << std::endl;
	std::cout << "Type: " << meta->getType() << std::endl;
	meta->makeSound();
	std::cout << std::endl;
	std::cout << "🐾 Dog" << std::endl;
	std::cout << "Type: " << dog->getType() << std::endl;
	dog->makeSound();
	std::cout << std::endl;
	std::cout << "🐾 Cat" << std::endl;
	std::cout << "Type: " << cat->getType() << std::endl;
	cat->makeSound();
	std::cout << std::endl;
	std::cout << "❌ WrongAnimal" << std::endl;
	std::cout << "Type: " << wrongMeta->getType() << std::endl;
	wrongMeta->makeSound();
	std::cout << std::endl;
	std::cout << "❌ WrongCat" << std::endl;
	std::cout << "Type: " << wrongCat->getType() << std::endl;
	wrongCat->makeSound();
	std::cout << "----------------------------------" << std::endl;


	delete wrongMeta;
	delete wrongCat;
	delete meta;
	delete dog;
	delete cat;
	return 0;
}