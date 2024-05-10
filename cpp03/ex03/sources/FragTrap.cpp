/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:56:18 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/10 18:11:36 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FragTrap.hpp"

/* ************************************************************************** */
/*       Constructors, Assignment Operator & Destructor                       */
/* ************************************************************************** */

FragTrap::FragTrap( void ) {

	std::cout << "Default Constructor FragTrap called" << std::endl;

	return;
}

FragTrap::FragTrap( std::string name ) : ClapTrap( name ) {

	if (this->_hitPoints == 10)
		this->_hitPoints = 100;
	if (this->_energyPoints == 10)
		this->_energyPoints = 100;
	this->_attackDamage = 30;

	std::cout << "Constructor FragTrap called" << std::endl;
	
	return ;
}

FragTrap::FragTrap( FragTrap const & src ) : ClapTrap( src ) {

	std::cout << "Copy constructor FragTrap called" << std::endl;

	*this = src;

	return ;
}


FragTrap::~FragTrap( void ) {

	std::cout << "Destructor FragTrap called" << std::endl;

	return ;
}

FragTrap &	FragTrap::operator=( FragTrap const & rhs ) {

	this->_name = rhs.getName();
	this->_hitPoints = rhs.getHitPoints();
	this->_energyPoints = rhs.getEnergyPoints();
	this->_attackDamage = rhs.getAttackDamage();

	return *this ;
}

/* ************************************************************************** */
/*            			Other Member Functions		                          */
/* ************************************************************************** */


void	FragTrap::highFivesGuys( void ) {

	std::cout << this->_name << ": 'That was awesome! High five!'" << std::endl;

	return ;
}