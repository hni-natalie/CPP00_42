/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hni-xuan <hni-xuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 14:20:35 by hni-xuan          #+#    #+#             */
/*   Updated: 2025/06/18 17:47:55 by hni-xuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : nextIndex(0), contactCounts(0) {}

bool PhoneBook::isAlphaOnly(const std::string &str) const {
	if (str.empty())
		return false;

	for (size_t i = 0; i < str.length(); i++) {
		if (!std::isalpha(str[i]) && !std::isspace(str[i]))
			return false;
	}
	return true;
}

bool PhoneBook::isDigitOnly(const std::string &str) const {
	if (str.empty())
		return false;

	for (size_t i = 0; i < str.length(); i++) {
		if (!std::isdigit(str[i]))
			return false;
	}
	return true;
}

void PhoneBook::add_contact() {
	std::string first, last, nick, phone, secret;
	
	// get first name
	std::cout << "First Name: ";
	std::getline(std::cin, first);
	if (!isAlphaOnly(first)) {
		std::cout << "First name must contain only letters.\n";
		return;
	}
	
	// get last name
	std::cout << "Last Name: ";
	std::getline(std::cin, last);
	if (!isAlphaOnly(last)) {
		std::cout << "Last name must contain only letters.\n";
		return;
	}

	// get nickname
	std::cout << "Nickname: ";
	std::getline(std::cin, nick);
	if (!isAlphaOnly(nick)) {
		std::cout << "Nickname must contain only letters.\n";
		return;
	}
	
	// get phone number
	std::cout << "Phone number: ";
	std::getline(std::cin, phone);
	if (!isDigitOnly(phone)) {
		std::cout << "Phone number must contain only numbers.\n";
		return;
	}
	
	// get darkest secret
	std::cout << "Darkest secret: ";
	std::getline(std::cin, secret);
	if (secret.empty()) {
		std::cout << "Darkest secret must not be empty.\n";
		return;
	}
	
	// set all the details
	contacts[nextIndex].set_contact(first, last, nick, phone, secret);
	nextIndex = (nextIndex + 1) % 8;
	if (contactCounts < 8)
		contactCounts ++;
	std::cout << "Contact added.\n";
}

void PhoneBook::search_contact() const {
	// header
	std::cout << std::setw(10) << "Index" << "|"
			<< std::setw(10) << "First Name" << "|"
			<< std::setw(10) << "Last Name" << "|"
			<< std::setw(10) << "Nickname" << "\n";

	// display first 10 character each
	for (size_t i = 0; i < contactCounts; i++) {
		contacts[i].displayShort(i); 
	}

	// get index
	std::cout << "Enter index to view full info: ";
	std::string input;
	std::getline(std::cin, input);
	if (input.length() != 1 || input[0] < '0' || input[0] > '9') {
		std::cout << "Invalid index. Try Again.\n";
		return;
	}

	// ensure valid index  
	size_t index = input[0] - '0';
	if (index >= contactCounts) {
		std::cout << "No contact at this index.\n";
		return;
	}

	// display full detail
	contacts[index].displayFull();
}