/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hni-xuan <hni-xuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:29:44 by hni-xuan          #+#    #+#             */
/*   Updated: 2025/06/18 14:11:17 by hni-xuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// import this library to use std library
#include <iostream>

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
		
	for (int i = 1; i < argc; ++i)
	{
		char *ptr = argv[i];
		while (*ptr)
		{
			if(*ptr >= 'a' && *ptr <= 'z')
				*ptr -= 'a' - 'A';
			ptr++;
		}
		std::cout << argv[i];
	}
	std::cout << std::endl;
	return 0;
}
