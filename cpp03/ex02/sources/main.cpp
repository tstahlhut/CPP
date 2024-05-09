/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:35:18 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/09 15:17:55 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FragTrap.hpp"
#include "../includes/ScavTrap.hpp"

int	main( void )
{
	
	FragTrap	Frag("Frag");
	std::cout << Frag.getName() << " enters with ";
	std::cout << Frag.getHitPoints() << " hit Points, ";
	std::cout << Frag.getEnergyPoints() << " energy points and ";
	std::cout << Frag.getAttackDamage() << " attack damage." << std::endl;

/*	ScavTrap	Scav("Scav");
	std::cout << Scav.getName()  << " enters with ";
	std::cout << Scav.getHitPoints() << " hit Points, ";
	std::cout << Scav.getEnergyPoints() << " energy points and ";
	std::cout << Scav.getAttackDamage() << " attack damage." << std::endl;

	
	Frag.attack("Scav");
	Scav.takeDamage(30);
	Scav.guardGate();
	Scav.attack("Frag");
	Frag.takeDamage(20);
	Frag.beRepaired(10);
	Scav.beRepaired(30);
*/

	Frag.highFivesGuys();

	return 0;
}