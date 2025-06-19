/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hni-xuan <hni-xuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 14:25:25 by hni-xuan          #+#    #+#             */
/*   Updated: 2025/06/19 14:51:41 by hni-xuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
	private:
		// fixed array, no dynamic allocation
		Contact contacts[8];
		int nextIndex;
		size_t contactCounts;
		bool isAlphaOnly(const std::string &str) const;
		bool isDigitOnly(const std:: string &str) const;
		
	public:
		// const is added after the function declaration
		// to promise this function won't change any member variables
		// member variables are the variables declared inside a class
		
		// constructor is required to initialise nextIndex and contactCounts value
		PhoneBook();
		void add_contact();
		void search_contact() const;
};

#endif