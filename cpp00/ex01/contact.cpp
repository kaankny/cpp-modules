/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanyilm <42kocaeli.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:34:32 by kkanyilm          #+#    #+#             */
/*   Updated: 2024/02/27 14:34:34 by kkanyilm         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

/*
	Constructor
*/
Contact::Contact()
{
}

/*
	Destructor
*/
Contact::~Contact()
{
}

/*
	Get name
*/
std::string Contact::getName() const
{
	return _name;
}

/*
	Get surname
*/
std::string Contact::getSurname() const
{
	return _surname;
}

/*
	Get nickname
*/
std::string Contact::getNickname() const
{
	return _nickname;
}

/*
	Get phone number
*/
std::string Contact::getPhoneNumber() const
{
	return _phoneNumber;
}

/*
	Get darkest secret
*/
std::string Contact::getDarkestSecret() const
{
	return _darkestSecret;
}

/*
	Set name
*/
void Contact::setName(std::string name)
{
	_name = name;
}

/*
	Set surname
*/
void Contact::setSurname(std::string surname)
{
	_surname = surname;
}

/*
	Set nickname
*/
void Contact::setNickname(std::string nickname)
{
	_nickname = nickname;
}

/*
	Set phone number
*/
void Contact::setPhoneNumber(std::string phoneNumber)
{
	_phoneNumber = phoneNumber;
}

/*
	Set darkest secret
*/
void Contact::setDarkestSecret(std::string darkestSecret)
{
	_darkestSecret = darkestSecret;
}
