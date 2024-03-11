/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:18:35 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/03/11 16:30:03 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#define RED "\e[31m"
#define YELLOW "\e[33m"
#define WHITE "\e[37m"

int	main( void )
{
	std::string	str = "HI THIS IS BRAIN";

	std::string*	stringPTR = &str;
	std::string&	stringREF = str;

	std::cout << "Memory address of string:         " << &str << std::endl;
	std::cout << "Memory address held by stringPTR: " << stringPTR << std::endl;
	std::cout << "Memory address held by stringREF: " << &stringREF << std::endl;

	std::cout << "Value of string:               " << str << std::endl;
	std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value pointed to by stringREF: " << stringREF << std::endl;

	return 0;
}