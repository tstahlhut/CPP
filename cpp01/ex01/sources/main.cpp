/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:18:35 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/03/11 16:01:33 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#define RED "\e[31m"
#define YELLOW "\e[33m"
#define WHITE "\e[37m"

int	main( void )
{
	std::cout << RED << "Welcome to the Graveyard!" << std::endl;
	std::cout << "----------------------" << std::endl;
	std::cout << "All the bodies in the graves are dead. But you may call a horde alive!" << std::endl;
	std::cout << "Tell me the name of the horde ... in one word ... " << WHITE << std::endl;

	std::string	names;	
	std::cin >> names;
	if (std::cin.fail())
		return 1;

	std::cout << RED << "... and how many they are ..." << WHITE << std::endl;
	int	number;
	std::cin >> number;
	if (std::cin.fail())
		return 1;
	
	Zombie* myZombies = zombieHorde(number, names);

	std::cout << RED << "Your zombies have been called ... and they rise from their graves ..." << WHITE << std::endl;

	for (int i = 0; i < number; i++) 
	{
		myZombies[i].announce();
	}

	std::cout << RED << "Dawn is near ... the " << YELLOW << "sun" << RED << " rises ... " << YELLOW << std::endl;

	delete [] myZombies;

	std::cout << WHITE;

	return 0;
}