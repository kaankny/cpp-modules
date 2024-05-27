/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanyilm <42kocaeli.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 14:02:08 by kkanyilm          #+#    #+#             */
/*   Updated: 2024/03/09 14:43:25 by kkanyilm         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
	protected:
		std::string _name;
		int			_hitPoint;
		int			_energyPoint;
		int			_attackDamage;
	public:
		ClapTrap();
		ClapTrap(const std::string name);
		ClapTrap(ClapTrap &copy);
		~ClapTrap();
		ClapTrap &operator=(ClapTrap &copy);
		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif