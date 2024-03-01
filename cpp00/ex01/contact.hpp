/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkanyilm <42kocaeli.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:33:18 by kkanyilm          #+#    #+#             */
/*   Updated: 2024/02/27 16:22:09 by kkanyilm         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact
{
	public:
		Contact();
		~Contact();
		std::string getName() const;
		std::string getSurname() const;
		std::string getNickname() const;
		std::string getPhoneNumber() const;
		std::string getDarkestSecret() const;
		void setName(std::string name);
		void setSurname(std::string surname);
		void setNickname(std::string nickname);
		void setPhoneNumber(std::string phoneNumber);
		void setDarkestSecret(std::string darkestSecret);
	private:
		std::string _name;
		std::string _surname;
		std::string _nickname;
		std::string _phoneNumber;
		std::string _darkestSecret;
};

#endif