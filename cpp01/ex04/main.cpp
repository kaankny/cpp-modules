/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanyilm <42kocaeli.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 12:30:29 by kkanyilm          #+#    #+#             */
/*   Updated: 2024/02/29 14:02:31 by kkanyilm         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int	main(int ac, char **av)
{
	std::string		filename;
	std::string		new_filename;
	std::string		s1;
	std::string		s2;
	std::string		line;
	std::ifstream	infile;
	std::ofstream	outfile;

	if (ac != 4)
	{
		std::cout << "Usage: ./ex04 <filename> <s1> <s2>" << std::endl;
		return (1);
	}
	filename = av[1];
	new_filename = filename + ".replace";
	s1 = av[2];
	s2 = av[3];
	infile.open(filename);
	if (!infile.is_open())
	{
		std::cout << "Error: file not found" << std::endl;
		return (1);
	}
	outfile.open(new_filename);
	if (!outfile.is_open())
	{
		infile.close();
		std::cout << "Error: file cannot be created" << std::endl;
		return (1);
	}
	while (std::getline(infile, line))
	{
		size_t	pos = 0;
		while ((pos = line.find(s1, pos)) != std::string::npos)
		{
			line.erase(pos, s1.length());
			line.insert(pos, s2);
			pos += s2.length();
		}
		outfile << line << std::endl;
	}
	infile.close();
	outfile.close();
	return (0);
}