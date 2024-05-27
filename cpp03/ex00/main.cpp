/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanyilm <42kocaeli.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 14:19:18 by kkanyilm          #+#    #+#             */
/*   Updated: 2024/03/09 14:25:48 by kkanyilm         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main()
{
	ClapTrap claptrap("Kaan");
	ClapTrap claptrap2(claptrap);
	ClapTrap claptrap3 = claptrap;

	claptrap.attack("target");
	claptrap.takeDamage(5);
	claptrap.takeDamage(5);
	claptrap.takeDamage(5);
	claptrap.beRepaired(5);
	return (0);
}