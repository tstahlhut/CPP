/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:35:18 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/08 14:26:53 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main( void )
{
	ClapTrap	Trap("Trap");

	Trap.takeDamage(6);
	Trap.beRepaired(1);
	Trap.beRepaired(1);
	Trap.attack("the enemy"); // cannot attack because damage points are 0
	Trap.attack("the enemy");
	Trap.takeDamage(4);
	Trap.beRepaired(2);
	Trap.beRepaired(2);
	Trap.attack("the enemy");
	Trap.takeDamage(5);
	Trap.beRepaired(2);
	Trap.attack("the enemy");
	Trap.beRepaired(2);
	Trap.beRepaired(2);
	Trap.takeDamage(5);
	Trap.beRepaired(2);
	Trap.attack("the enemy");
	return 0;
}