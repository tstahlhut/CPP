/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:12:29 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/24 17:38:18 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main( int argc, char **argv ) {

	if (argc != 2) {
		std::cout << "1 argument required and only 1 argument allowed" << std::endl;
		return 0;
	}
	ScalarConverter::convert(argv[1]);
	return 0;
}

/* tested:
	48
	0
	42.0f
	%
	y
	c
	a
	2147483647
	0.0, -4.2, 4.2
	0.0f, -4.2f, 4.2f
	To Do: 
	- max und min fuer float, so that it prints "impossible"
	- nan
	- -inff
	- +inff
	- nanf
	- -inf
	- +inf
*/