/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanyilm <42kocaeli.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 14:43:54 by kkanyilm          #+#    #+#             */
/*   Updated: 2024/03/09 15:19:02 by kkanyilm         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	_name = "ScavTrap";
	_hitPoint = 100;
	_energyPoint = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap name constructor called" << std::endl;
	_hitPoint = 100;
	_energyPoint = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap(ScavTrap &copy) : ClapTrap(copy)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap &copy)
{
	std::cout << "ScavTrap assignation operator called" << std::endl;
	this->_name = copy._name;
	this->_hitPoint = copy._hitPoint;
	this->_energyPoint = copy._energyPoint;
	this->_attackDamage = copy._attackDamage;
	return (*this);
}

void ScavTrap::attack(const std::string &target)
{
	if (this->_hitPoint < 1)
	{
		std::cout << "💀 ScavTrap " << _name << " is dead and can't attack " << target << "anymore!" << std::endl;
		return ;
	}
	if (this->_energyPoint < 1)
	{
		std::cout << "😴 ScavTrap " << _name << " has no energy to attack " << target << " anymore!" << std::endl;
		return ;
	}
	std::cout << "🔫 ScavTrap " << _name << " attacks " << target << " causing " << _attackDamage << " points of damage!" << std::endl;
	this->_energyPoint -= 1;
	std::cout << "💧 ScavTrap " << _name << " has " << _energyPoint << " energy points left!" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "🛡️ ScavTrap " << _name << " has entered in Gate keeper mode!" << std::endl;
}
