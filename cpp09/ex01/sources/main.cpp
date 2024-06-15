/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 15:35:31 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/06/14 17:12:34 by tstahlhu         ###   ########.fr       */
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
	}

	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << calc << std::endl;
	

	return 0;
}