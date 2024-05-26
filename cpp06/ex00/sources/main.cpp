/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:12:29 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/26 15:54:56 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

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

MAX & MINS:
	./convert -128
	./convert -127
	./convert 255
	./convert 256

	./convert -2147483648
	./convert -2147483649 -> float somehow rounds differently, if I print without setprecision and fixed, double and float are the same
	./convert 2147483648
	./convert 2147483647

	./convert 340282346638528859811704183484516925440 (FLT_MAX)
	./convert 34028234663852885981170418348451692544
	./convert 3402823466385288598117041834845169254401 --> exceeds FLT_MAX


	./convert 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368

	- nan
	- -inff
	- +inff
	- nanf
	- -inf
	- +inf
*/