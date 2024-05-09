/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:24:38 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/09 14:51:49 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// This is the implementation of the ClapTrap class

#include "ClapTrap.hpp"
#include <iostream>

/* ************************************************************************** */
/*       Constructors, Assignment Operator & Destructor                       */
/* ************************************************************************** */


ClapTrap::ClapTrap( void ) {

	std::cout << "Default Constructor ClapTrap called" << std::endl;

	return ;
}

ClapTrap::ClapTrap( std::string name ) : _name( name ) {

	std::cout << "Constructor ClapTrap called" << std::endl;

	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;

	return ;
}

ClapTrap::ClapTrap( ClapTrap const & src ) {

	std::cout << "Copy Constructor ClapTrap called" << std::endl;

	*this = src ;

	return ;
}

ClapTrap &	ClapTrap::operator=( ClapTrap const & rhs ) {

	std::cout << "Copy assignement operator ClapTrap called" << std::endl;

	this->_name = rhs.getName();
	this->_hitPoints = rhs.getHitPoints();
	this->_energyPoints = rhs.getEnergyPoints();
	this->_attackDamage = rhs.getAttackDamage();

	return *this ;
}

ClapTrap::~ClapTrap( void ) {

	std::cout << "Destructor ClapTrap called" << std::endl;

	return ;
}

/* ************************************************************************** */
/*            			Getter Functions		                              */
/* ************************************************************************** */


std::string	ClapTrap::getName( void ) const {

	return this->_name;
}

unsigned int	ClapTrap::getHitPoints( void ) const {

	return this->_hitPoints;
}

unsigned int	ClapTrap::getEnergyPoints( void ) const {

	return this->_energyPoints;
}

unsigned int	ClapTrap::getAttackDamage( void ) const {

	return this->_attackDamage;
}

/* ************************************************************************** */
/*            			Other Member Functions		                          */
/* ************************************************************************** */


void	ClapTrap::attack( const std::string& target ) {

	// loses 1 energy point for attacking
	if (this->_hitPoints == 0)
		std::cout << this->_name << " is out of health and cannot attack." << std::endl;
	else if (this->_energyPoints == 0)
		std::cout << this->_name << " is out of energy and cannot attack." << std::endl;
	else {

		this->_energyPoints -= 1;
		
		if (this->_attackDamage <= 0)
			std::cout << this->_name << "'s attack causes no damage to " << target << "." << std::endl;
		else if (target == this->_name)
			std::cout << this->_name << " attacks itself, causing " << this->_attackDamage << " points of damage!" << std::endl;
		else
			std::cout << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	}
	return ;
}

void	ClapTrap::takeDamage( unsigned int amount ) {

	std::cout << this->_name << " was attacked and lost " << amount << " hit points! ";
	if (amount > this->_hitPoints)
		this->_hitPoints = 0;
	else
		this->_hitPoints -= amount;
	std::cout << "Health is now " << this->_hitPoints << "." << std::endl;
	return ;
}


void	ClapTrap::beRepaired( unsigned int amount ) {

	if (this->_hitPoints == 0)
		std::cout << this->_name << " is out of health and cannot repair." << std::endl;
	else if (this->_energyPoints == 0)
		std::cout << this->_name << " is out of energy and cannot repair." << std::endl;
	else {
		this->_energyPoints -= 1;
		this->_hitPoints += amount;
		std::cout << this->_name << " repaired itself and got " << amount << " hit points. ";
		std::cout << "Health is now " << this->_hitPoints << "." << std::endl;
	}
	return ;
}