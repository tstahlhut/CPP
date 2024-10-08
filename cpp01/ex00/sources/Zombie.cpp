/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:19:13 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/04/29 17:29:16 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

//Constructor
Zombie::Zombie	( void )
{
	std::cout << "Zombie constructor called" << std::endl;
	return ;
}

Zombie::Zombie	( std::string name )
{
	this->_name = name;
	std::cout << "Zombie constructor called: " << name << " created" << std::endl;
	return ;
}

//Destructor
Zombie::~Zombie	( void )
{
	std::cout << "Zombie destructor called: "<< this->_name << " deleted" << std::endl;
	return ;
}

void	Zombie::announce( void )
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl; 
}