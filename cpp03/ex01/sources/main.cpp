/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:35:18 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/09 14:26:39 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main( void )
{
	ClapTrap	Trap("Trap");
	ScavTrap	Scav("Scav");

	std::cout << Trap.getName() << " enters with ";
	std::cout << Trap.getHitPoints() << " hit Points, ";
	std::cout << Trap.getEnergyPoints() << " energy points and ";
	std::cout << Trap.getAttackDamage() << " attack damage." << std::endl;

	std::cout << Scav.getName()  << " enters with ";
	std::cout << Scav.getHitPoints() << " hit Points, ";
	std::cout << Scav.getEnergyPoints() << " energy points and ";
	std::cout << Scav.getAttackDamage() << " attack damage." << std::endl;

	
	Trap.attack("Scav");
	Scav.guardGate();
	Scav.attack("Trap");
	Trap.takeDamage(20);
	Trap.beRepaired(1);
	Scav.takeDamage(50);
	Scav.attack("unknown enemy");
	Scav.beRepaired(10);
	Scav.takeDamage(60);
	Scav.beRepaired(10);

	/*ScavTrap Clone = Scav;
	std::cout << Clone.getName() << " enters with ";
	std::cout << Clone.getHitPoints() << " hit Points, ";
	std::cout << Clone.getEnergyPoints() << " energy points and ";
	std::cout << Clone.getAttackDamage() << " attack damage." << std::endl;*/
	return 0;
}