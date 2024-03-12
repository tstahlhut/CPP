/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:49:09 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/03/12 17:46:45 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

/*********** CONSTRUCTOR ******************************/

HumanB::HumanB( std::string const name ) : _name(name)
{
	std::cout << this->_name << " entered the ring unarmed" << std::endl;
	return ;
}

/*********** DESTRUCTOR ******************************/

HumanB::~HumanB( void )
{
	std::cout << this->_name << " left the ring" << std::endl;
	return ;
}

/*********** MEMBER FUNCTIONS ******************************/

void	HumanB::attack( void )
{
	std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
	return ;
}

void	HumanB::setWeapon( Weapon& weapon )
{
	this->_weapon = &weapon;
	std::cout << this->_name << " takes up a " << this->_weapon->getType() << std::endl;
	return ;
}