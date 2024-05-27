/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanyilm <42kocaeli.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:32:40 by kkanyilm          #+#    #+#             */
/*   Updated: 2024/02/29 14:12:10 by kkanyilm         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	std::cout << "Harl is born." << std::endl;
}

Harl::~Harl()
{
	std::cout << "Harl is dead." << std::endl;
}

void	Harl::complain(std::string level)
{
	int i = 0;
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void	(Harl::*complaints[4])(void) = 
	{
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};

	for(; i < 4; i++)
		if (levels[i] == level)
			break;
	switch (i)
	{
		case 0:
			(this->*complaints[i++])();
		case 1:
			(this->*complaints[i++])();
		case 2:
			(this->*complaints[i++])();
		case 3:
			(this->*complaints[i++])();
			break;
		default:
			std::cout << "I have nothing to say." << std::endl;
	}
}

void	Harl::debug(void)
{
	std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
}
