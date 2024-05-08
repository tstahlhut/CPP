/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:21:40 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/07 14:07:03 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main( void )
{
	Fixed	a;
	Fixed	b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed	c( Fixed( 16 ) / Fixed( 4 ) );	// 4
	Fixed	d( Fixed( 2.5f ) + Fixed( 2 ) ); // 4.5
	

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << --a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	if (b > c)
		std::cout << "b is greater than c" << std::endl;
	if (c != d)
		std::cout << "c is unequal to d" << std::endl;
	if (c < d)
		std::cout << "c is smaller than d" << std::endl;
	
	b = d - c;

	std::cout << "b is " << b << std::endl;

	d = d - b;

	if (c == d)
		std::cout << "c is equal to d" << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << Fixed::min( c, d ) << std::endl;

	return 0;
}