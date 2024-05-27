/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanyilm <42kocaeli.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 13:55:07 by kkanyilm          #+#    #+#             */
/*   Updated: 2024/03/09 14:53:28 by kkanyilm         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap default constructor called" << std::endl;
	_name = "ClapTrap";
	_hitPoint = 10;
	_energyPoint = 10;
	_attackDamage = 0;
}

ClapTrap::ClapTrap(const std::string name)
{
	std::cout << "ClapTrap name constructor called" << std::endl;
	_name = name;
	_hitPoint = 10;
	_energyPoint = 10;
	_attackDamage = 0;
}

ClapTrap::ClapTrap(ClapTrap &copy)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	this->_name = copy._name;
	this->_hitPoint = copy._hitPoint;
	this->_energyPoint = copy._energyPoint;
	this->_attackDamage = copy._attackDamage;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap &copy)
{
	std::cout << "ClapTrap assignation operator called" << std::endl;
	this->_name = copy._name;
	this->_hitPoint = copy._hitPoint;
	this->_energyPoint = copy._energyPoint;
	this->_attackDamage = copy._attackDamage;
	return (*this);
}

void ClapTrap::attack(const std::string &target)
{
	if (this->_hitPoint < 1)
	{
		std::cout << "💀 ClapTrap " << _name << " is dead and can't attack " << target << " anymore! " << std::endl;
		return ;
	}
	if (this->_energyPoint < 1)
	{
		std::cout << "😴 ClapTrap " << _name << " has no energy point to attack " << target << std::endl;
		return ;
	}
	std::cout << "🗡️  ClapTrap " << _name << " attack " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
	this->_energyPoint -= 1;
	std::cout << "💧 ClapTrap " << _name << " has " << _energyPoint << " energy points left" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoint < 1)
	{
		std::cout << "💀 ClapTrap " << _name << " is already dead" << std::endl;
		return ;
	}
	std::cout << "🩸 ClapTrap " << _name << " take " << amount << " points of damage!" << std::endl;
	this->_hitPoint -= amount;
	if (this->_hitPoint < 1)
	{
		std::cout << "💀 ClapTrap " << _name << " is dead" << std::endl;
	}
	else
	{
		std::cout << "🩸 ClapTrap " << _name << " has " << _hitPoint << " hit points left" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoint < 1)
	{
		std::cout << "😴 ClapTrap " << _name << " has no energy point to repair" << std::endl;
		return ;
	}
	std::cout << "💉 ClapTrap " << _name << " repaired " << amount << " points of damage!" << std::endl;
	this->_hitPoint += amount;
	this->_energyPoint -= 1;
	std::cout << "🩸 ClapTrap " << _name << " has " << _hitPoint << " hit points now" << std::endl;
	std::cout << "💧 ClapTrap " << _name << " has " << _energyPoint << " energy points left" << std::endl;
}
