/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanyilm <42kocaeli.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:33:54 by kkanyilm          #+#    #+#             */
/*   Updated: 2024/02/27 14:43:35 by kkanyilm         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include "contact.hpp"

class Phonebook
{
	public:
		Phonebook();
		~Phonebook();
		void addContact(Contact contact);
		Contact getContact(int index) const;
		int getContactsCount() const;
	private:
		Contact _contacts[8];
		int _contactsCount;
		int _index;
};

#endif
