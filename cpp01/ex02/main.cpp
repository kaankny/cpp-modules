/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanyilm <42kocaeli.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 11:59:46 by kkanyilm          #+#    #+#             */
/*   Updated: 2024/02/29 14:01:14 by kkanyilm         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main()
{
	std::string	kaan = "HI THIS IS BRAIN";
	std::string *stringPTR = &kaan;
	std::string &stringREF = kaan;

	std::cout << "Address of the string    : " << &kaan << std::endl;
	std::cout << "Address of the stringPTR : " << stringPTR << std::endl;
	std::cout << "Address of the stringREF : " << &stringREF << std::endl;

	std::cout << "Value of the string    : " << kaan << std::endl;
	std::cout << "Value of the stringPTR : " << *stringPTR << std::endl;
	std::cout << "Value of the stringREF : " << stringREF << std::endl;
	return (0);
}
