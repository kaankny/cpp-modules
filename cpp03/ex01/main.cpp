/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanyilm <42kocaeli.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 14:19:18 by kkanyilm          #+#    #+#             */
/*   Updated: 2024/03/09 15:03:02 by kkanyilm         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main()
{
	ScavTrap scavtrap("Kaan");
	ScavTrap scavtrap2(scavtrap);
	ScavTrap scavtrap3 = scavtrap;

	scavtrap.attack("target");
	scavtrap.takeDamage(5);
	scavtrap.takeDamage(5);
	scavtrap.takeDamage(5);
	scavtrap.beRepaired(5);
	scavtrap.guardGate();
	return (0);
}