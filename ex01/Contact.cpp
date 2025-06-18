/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hni-xuan <hni-xuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:21:02 by hni-xuan          #+#    #+#             */
/*   Updated: 2025/06/18 17:45:30 by hni-xuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::set_contact(const std::string &first, const std::string &last, const std::string &nick, const std::string &phone, const std::string &secret) {
	firstName = first;
	lastName = last;
	nickname = nick;
	phoneNumber = phone;
	darkestSecret = secret;
}

// If the text is longer than the column, 
// it must be truncated and the last displayable character must be replaced by a dot (’.’)
std::string Contact::formatField(const std::string &str) const {
		if (str.length() > 10)
			return str.substr(0, 9) + ".";
		else
			return str;
	};

void Contact::displayShort(int index) const {
	std::cout << std::setw(10) << index << "|"
			<< std::setw(10) << formatField(firstName) << "|"
			<< std::setw(10) << formatField(lastName) << "|"
			<< std::setw(10) << formatField(nickname) << "\n";
}

void Contact::displayFull() const {
	std::cout << "First Name: " << firstName << "\n";
	std::cout << "Last Name: " << lastName << "\n";
	std::cout << "Nickname: " << nickname << "\n";
	std::cout << "Phone Number: " << phoneNumber << "\n";
	std::cout << "Darkest Secret: " << darkestSecret << "\n";
}
