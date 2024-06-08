/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 17:37:04 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/06/08 18:58:41 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <../includes/iter.hpp>


void	print( int i ) {
	std::cout << i << std::endl;
	return ;
}

void	printStr( std::string str ) {
	std::cout << str << std::endl;
	return ;
}

void	increment( int & i ) {
	i += 1;
	return ;
}

int	main( void ) {

	int				a[3] = {1, 2, 3};
	float			empty[] = {};
	std::string		names[4] = {"Laura", "Linda", "Amelia", "Basket"};


	::iter( a, 3, print );	
	::iter( empty, 0, print );	
	::iter( names, 4, printStr );
	::iter( a, 3, increment );
	::iter( a, 3, print );
	
	return 0;
}