/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:35:18 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/10 17:54:11 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/DiamondTrap.hpp"

int	main( void )
{
	
	DiamondTrap	Diamond("Diamond");
	std::cout << Diamond.getName() << " enters with ";
	std::cout << Diamond.getHitPoints() << " hit Points, ";
	std::cout << Diamond.getEnergyPoints() << " energy points and ";
	std::cout << Diamond.getAttackDamage() << " attack damage." << std::endl;
	
	Diamond.attack("Scav");		// inherited from ScavTrap

	Diamond.guardGate();		// inherited from ScavTrap

	Diamond.highFivesGuys();	// inherited from FragTrap
	
	Diamond.whoAmI();

	return 0;
}