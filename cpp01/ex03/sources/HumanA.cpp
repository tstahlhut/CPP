/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:49:09 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/03/12 18:03:33 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanA.hpp"

/*********** CONSTRUCTOR ******************************/

HumanA::HumanA( std::string const name, Weapon const & someWeapon ): _name(name), _weapon(someWeapon)
{
	std::cout << this->_name << " enters the ring armed with a " << this->_weapon.getType() << std::endl;
	return ;
}

/*********** DESTRUCTOR ******************************/

HumanA::~HumanA( void )
{
	std::cout << this->_name << " left the ring" << std::endl;
	return ;
}

void	HumanA::attack( void )
{
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
	return ;
}