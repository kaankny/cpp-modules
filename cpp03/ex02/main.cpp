/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanyilm <42kocaeli.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 14:19:18 by kkanyilm          #+#    #+#             */
/*   Updated: 2024/03/09 15:10:22 by kkanyilm         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int	main()
{
	FragTrap fragtrap("Kaan");
	FragTrap fragtrap2(fragtrap);
	FragTrap fragtrap3 = fragtrap;

	fragtrap.attack("target");
	fragtrap.takeDamage(5);
	fragtrap.takeDamage(5);
	fragtrap.takeDamage(5);
	fragtrap.beRepaired(5);
	fragtrap.highFivesGuys();
	return (0);
}