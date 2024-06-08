/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 17:37:04 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/06/08 17:56:51 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <../includes/Swap.tpp>
#include <../includes/Comparisions.tpp>

int	main( void ) {

	int		a = 2;
	int		b = 3;


	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
//	float	f = 4.2;
//	::swap( a, f ); // should not work because the type of the two parameters has to be the same
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	//std::cout << "min( a, c ) = " << ::min( a, f ) << std::endl; 

	std::string	c = "chaine1";
	std::string	d = "chaine2";

	::swap( c, d );
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

}