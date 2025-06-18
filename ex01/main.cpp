/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hni-xuan <hni-xuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 14:51:31 by hni-xuan          #+#    #+#             */
/*   Updated: 2025/06/18 17:28:44 by hni-xuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main() {
	PhoneBook phoneBook;
	std::string command;

	std::cout << "Welcome to your PhoneBook!" << std::endl;
	while (true) {
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		if(!std::getline(std::cin, command)) {
			std::cout << "Input interrupted. Exit Program." << std::endl;
			break;
		}

		if (command == "ADD") {
			phoneBook.add_contact();
		} else if (command == "SEARCH") {
			phoneBook.search_contact();
		} else if (command == "EXIT") {
			std::cout << "Exiting the program" << std::endl; 
			break;	
		} else {
			std::cout << "Invalid command. Try Again." << std::endl;
		}
	}
	return 0;
}