/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanyilm <42kocaeli.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 15:07:38 by kkanyilm          #+#    #+#             */
/*   Updated: 2024/03/09 15:19:36 by kkanyilm         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "FragTrap default constructor called" << std::endl;
	_name = "FragTrap";
	_hitPoint = 100;
	_energyPoint = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap name constructor called" << std::endl;
	_hitPoint = 100;
	_energyPoint = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap(FragTrap &copy) : ClapTrap(copy)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap &copy)
{
	std::cout << "FragTrap assignation operator called" << std::endl;
	this->_name = copy._name;
	this->_hitPoint = copy._hitPoint;
	this->_energyPoint = copy._energyPoint;
	this->_attackDamage = copy._attackDamage;
	return (*this);
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "🖐  FragTrap " << this->_name << " is asking for a high five!" << std::endl;
}
