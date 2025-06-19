/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hni-xuan <hni-xuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:29:44 by hni-xuan          #+#    #+#             */
/*   Updated: 2025/06/19 13:30:26 by hni-xuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// import this library to use std library
#include <iostream>
#include <string>

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
		
	for (int i = 1; i < argc; i++)
	{
		std::string str = argv[i];
		for(int j = 0; j < str.length(); j++)
			str[j] = std::toupper(str[j]);
		std::cout << str;
	}
	std::cout << std::endl;
	return 0;
}

