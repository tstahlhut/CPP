/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:42:46 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/09 14:18:47 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

ScavTrap::ScavTrap( void ) {

	std::cout << "Default Constructor ScavTrap called" << std::endl;

	return;
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap( name ) {

	std::cout << "Constructor ScavTrap called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	return ;
}

ScavTrap::ScavTrap( ScavTrap const & src ) : ClapTrap( src ) {

	std::cout << "Copy constructor ScavTrap called" << std::endl;

	*this = src;

	return ;
}


ScavTrap::~ScavTrap( void ) {

	std::cout << "Destructor ScavTrap called" << std::endl;

	return ;
}

ScavTrap &	ScavTrap::operator=( ScavTrap const & rhs ) {

	this->_name = rhs.getName();
	this->_hitPoints = rhs.getHitPoints();
	this->_energyPoints = rhs.getEnergyPoints();
	this->_attackDamage = rhs.getAttackDamage();

	return *this ;
}

void	ScavTrap::attack( const std::string& target ) {

	// loses 1 energy point for attacking
	if (this->_hitPoints == 0)
		std::cout << this->_name << " cannot attack because it is out of health." << std::endl;
	else if (this->_energyPoints == 0)
		std::cout << this->_name << " cannot attack because it is out of energy." << std::endl;
	else {

		this->_energyPoints -= 1;
		
		if (this->_attackDamage <= 0)
			std::cout << this->_name << "'s attack causes no damage to " << target << "." << std::endl;
		else if (target == this->_name)
			std::cout << this->_name << " attacks itself with a force of " << this->_attackDamage << " damage points!" << std::endl;
		else
			std::cout << this->_name << " attacks " << target << " with a force of " << this->_attackDamage << " damage points!" << std::endl;
	}
	return ;
}

void	ScavTrap::guardGate( void ) {

	std::cout << this->_name << " is now in Gate keeper mode" << std::endl;

	return ;
}