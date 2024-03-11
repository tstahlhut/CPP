/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:49:09 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/03/11 17:47:44 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

/*********** CONSTRUCTOR ******************************/

HumanB::HumanB( std::string name )
{
	this->_name = name;
	return ;
}

/*********** DESTRUCTOR ******************************/

HumanB::~HumanB( void )
{
	std::cout << this->_name << " has been destroyed" << std::endl;
	return ;
}

void	HumanB::attack( void )
{
	std::cout << this->_name << " attacks with their " << this->weapon.getType << std::endl;
	return ;
}

void	HumanB::setWeapon( Weapon weapon )
{
	Weapon	weapon;
	this->weapon = &weapon;
	return ;
}