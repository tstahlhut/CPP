/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:49:09 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/03/11 17:02:27 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

/*********** CONSTRUCTOR ******************************/

HumanA::HumanA( std::string name, std::string weapon )
{
	this->_name = name;
	this->weapon.setType = weapon;
	return ;
}

/*********** DESTRUCTOR ******************************/

HumanA::~HumanA( void )
{
	std::cout << this->_name << " has been destroyed" << std::endl;
	return ;
}

void	HumanA::attack( void )
{
	std::cout << this->_name << " attacks with their " << this->weapon.getType << std::endl;
	return ;
}