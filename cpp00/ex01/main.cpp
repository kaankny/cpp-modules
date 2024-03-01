/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanyilm <42kocaeli.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:34:41 by kkanyilm          #+#    #+#             */
/*   Updated: 2024/02/28 12:31:00 by kkanyilm         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include "contact.hpp"
#include <iostream>
#include <iomanip>

/*
	getInput fonksiyonu, kullanıcıdan giriş almak için kullanılır.
*/
std::string getInput(std::string prompt)
{
    std::string input;
    while (true)
	{
        std::cout << prompt;
        if (!std::getline(std::cin, input))
		{
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (std::cin.eof())
			{
                std::cout << "EOF yakalandi. Program sonlandiriliyor." << std::endl;
                exit(0);
            }      
            std::cout << "Hatali giris. Lutfen tekrar deneyin." << std::endl;
        }
		else if (input.empty())
            std::cout << "Gecersiz giris. Lutfen bir seyler yazin." << std::endl;
		else
            break;
    }
    return input;
}

void	printContact(std::string str)
{
	if (str.length() > 10)
		std::cout << str.substr(0, 9) << ".";
	else
		std::cout << std::setw(10) << str;
}

int	check_is_digit(std::string str)
{
	for (unsigned int i = 0; i < str.length(); i++)
	{
		if (isdigit(str[i]) == false)
			return (false);
	}
	return (true);
}

int main()
{
	Phonebook phonebook;
	std::string command;
	while (true)
	{
		command = getInput("Enter command: ");
		if (command == "EXIT")
			break;
		else if (command == "ADD")
		{
			Contact contact;
			contact.setName(getInput("Enter name: "));
			contact.setSurname(getInput("Enter surname: "));
			contact.setNickname(getInput("Enter nickname: "));
			contact.setPhoneNumber(getInput("Enter phone number: "));
			contact.setDarkestSecret(getInput("Enter darkest secret: "));
			phonebook.addContact(contact);
		}
		else if (command == "SEARCH")
		{
			int contactsCount = phonebook.getContactsCount();
			if (contactsCount == 0)
			{
				std::cout << "No contacts found" << std::endl;
				continue;
			}
			std::cout << "     index|first name| last name|  nickname" << std::endl;
			for (int i = 0; i < contactsCount; i++)
			{
				Contact contact = phonebook.getContact(i);
				std::cout << std::setw(10) << i << "|";
				printContact(contact.getName());
				std::cout << "|";
				printContact(contact.getSurname());
				std::cout << "|";
				printContact(contact.getNickname());
				std::cout << std::endl;
			}
			std::string inp = getInput("Enter index: ");
			if (check_is_digit(inp) == false)
			{
				std::cout << "Invalid index" << std::endl;
				continue;
			}
			int index = std::stoi(inp);
			if (index >= 0 && index < contactsCount)
			{
				Contact contact = phonebook.getContact(index);
				std::cout << "Name           : " << contact.getName() << std::endl;
				std::cout << "Surname        : " << contact.getSurname() << std::endl;
				std::cout << "Nickname       : " << contact.getNickname() << std::endl;
				std::cout << "Phone number   : " << contact.getPhoneNumber() << std::endl;
				std::cout << "Darkest secret : " << contact.getDarkestSecret() << std::endl;
			}
			else
			{
				std::cout << "Invalid index" << std::endl;
			}
		}
		else
		{
			std::cout << "Invalid command" << std::endl;
		}
	}
	return 0;
}
