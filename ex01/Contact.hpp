/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hni-xuan <hni-xuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 14:28:38 by hni-xuan          #+#    #+#             */
/*   Updated: 2025/06/18 17:31:31 by hni-xuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
// used for output formatting 
// std::setw(n) make sure each column is exactly n characters wide
#include <iomanip>

class Contact {
	private:
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string phoneNumber;
		std::string darkestSecret;
		std::string formatField(const std::string &str) const;
		
		public:
		void set_contact(const std::string &first, const std::string &last, 
			const std::string &nick, const std::string &phone, const std::string &secret);
		void displayShort(int index) const;
		void displayFull() const;
};

#endif