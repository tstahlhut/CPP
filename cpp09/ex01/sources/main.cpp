/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 15:35:31 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/08/26 18:58:10 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"
#include <iostream>

int	main( int argc, char **argv ) {

	if (argc != 2) {
		std::cout << "Error: 1 inverted Polish mathematical expression required" << std::endl;
		return 0;
	}

	RPN	calc;

	try {
	for (int i = 0; argv[1][i] != '\0'; i++) {
		calc.put(argv[1][i]);
		if (argv[1][++i] == '\0')  //for space between numbers and operators
			break ;
	
	}
	if (calc.getStack().size() > 1 || calc.getStack().empty())
		throw RPN::WrongSymbolException();

	std::cout << calc;
	}

	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	

	return 0;
}