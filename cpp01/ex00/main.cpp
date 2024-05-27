/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanyilm <42kocaeli.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 11:59:24 by kkanyilm          #+#    #+#             */
/*   Updated: 2024/02/29 13:54:04 by kkanyilm         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void	randomChump(std::string name);

int	main(void)
{
	Zombie *zombie1 = newZombie("Zombie1");
	zombie1->announce();
	randomChump("Zombie2");
	delete zombie1;
	return (0);
}
