/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:35:18 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/08 11:39:12 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main( void )
{
	ClapTrap	ClapTrap1("Clap");
	ClapTrap	ClapTrap2("Trap");

	ClapTrap1.attack("Trap");
	ClapTrap2.takeDamage(0); // I do not understand the damage points: can claptrap cause no damage?!

}