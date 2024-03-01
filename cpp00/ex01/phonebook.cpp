/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanyilm <42kocaeli.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:34:43 by kkanyilm          #+#    #+#             */
/*   Updated: 2024/02/27 16:22:54 by kkanyilm         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

/*
	Constructor
*/
Phonebook::Phonebook()
{
	_contactsCount = 0;
	_index = 0;
}

/*
	Destructor
*/
Phonebook::~Phonebook()
{
}

/*
	Add contact
*/
void Phonebook::addContact(Contact contact)
{
	if (_index >= 8)
		_index = 0;
	_contacts[_index] = contact;
	if (_contactsCount < 8)
		_contactsCount++;
	_index++;
}

/*
	Get contact
*/
Contact Phonebook::getContact(int index) const
{
	return _contacts[index];
}

/*
	Get contacts count
*/
int Phonebook::getContactsCount() const
{
	return _contactsCount;
}
