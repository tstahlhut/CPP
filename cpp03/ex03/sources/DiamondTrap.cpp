/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:49:30 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/10 18:10:29 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/DiamondTrap.hpp"

/* ************************************************************************** */
/*       Constructors, Assignment Operator & Destructor                       */
/* ************************************************************************** */

DiamondTrap::DiamondTrap( void ) {

	std::cout << "Default Constructor DiamondTrap called" << std::endl;

	return;
}

DiamondTrap::DiamondTrap( std::string name ) : ClapTrap( name + "_clap_name"), ScavTrap( name ), FragTrap( name ) {

	
	this->_name = name;
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::getEnergyPoints();
	this->_attackDamage = FragTrap::getAttackDamage();

	std::cout << "Constructor DiamondTrap called" << std::endl;
	

	return ;
}


DiamondTrap::DiamondTrap( DiamondTrap const & src ) : ClapTrap( src), ScavTrap( src ), FragTrap( src ) {

	std::cout << "Copy constructor DiamondTrap called" << std::endl;

	*this = src;

	return ;
}


DiamondTrap::~DiamondTrap( void ) {

	std::cout << "Destructor DiamondTrap called" << std::endl;

	return ;
}

DiamondTrap &	DiamondTrap::operator=( DiamondTrap const & rhs ) {

	this->_name = rhs.getName();
	this->_hitPoints = rhs.getHitPoints();
	this->_energyPoints = rhs.getEnergyPoints();
	this->_attackDamage = rhs.getAttackDamage();

	return *this ;
}

/* ************************************************************************** */
/*            			Other Member Functions		                          */
/* ************************************************************************** */

// instead of using "using" keyword in .hpp to define which of the inherited functions
// should be used, we could also redefine it like this: (this was my first approach)

/*void	DiamondTrap::attack( const std::string& target ) {

	ScavTrap::attack( target );

	return ;
}*/

void	DiamondTrap::whoAmI( void ) {

	std::cout << "My name is " << this->_name << " and my ClapTrap name is " << ClapTrap::_name << std::endl;
}
