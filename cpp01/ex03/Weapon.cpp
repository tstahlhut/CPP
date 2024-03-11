/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:36:03 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/03/11 18:25:15 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

/*********** CONSTRUCTOR ******************************/
Weapon::Weapon( void )
{
	std::cout << "Weapon constructed" << std::endl;
	return ;
}

Weapon::Weapon( std::string type )
{
	this->_type = type;
	std::cout << "Weapon of type " << type << "constructed" << std::endl;
	return ;
}

/*********** DESTRUCTOR ******************************/

Weapon::~Weapon( void )
{
	std::cout << Weapon
}

/*********** GETTER	******************************/

std::string	Weapon::getType( void ) const
{
	return this->_type;
}

/*********** SETTER	******************************/

void	Weapon::setType( std::string type)
{
	this->_type = type;
	return ;
}