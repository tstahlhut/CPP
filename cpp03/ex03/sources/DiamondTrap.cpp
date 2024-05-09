/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:49:30 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/09 16:04:03 by tstahlhu         ###   ########.fr       */
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

DiamondTrap::DiamondTrap( std::string name ) : ClapTrap( name ), ScavTrap( name ), FragTrap( name ) {

	std::cout << "Constructor DiamondTrap called" << std::endl;
	this->_name = name + ClapTrap::_name;
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	return ;
}

DiamondTrap::DiamondTrap( DiamondTrap const & src ) : ClapTrap( src ), ScavTrap( src ), FragTrap( src ) {

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
