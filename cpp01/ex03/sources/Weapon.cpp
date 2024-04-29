/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:36:03 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/04/29 17:47:34 by tstahlhu         ###   ########.fr       */
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
	std::cout << "Weapon of type " << type << " constructed" << std::endl;
	return ;
}

/*********** DESTRUCTOR ******************************/

Weapon::~Weapon( void )
{
	std::cout << "Weapon destroyed" << std::endl;
	return ;
}

/*********** GETTER	******************************/

std::string	Weapon::getType( void ) const
{
	std::string const&	type = this->_type;
	return type;
}

/*********** SETTER	******************************/

void	Weapon::setType( std::string type)
{
	this->_type = type;
	return ;
}