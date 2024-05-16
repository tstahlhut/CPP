/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:24:38 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/11 17:11:03 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Character.hpp"

// Default Constructor

Character::Character( void ) {

	std::cout << "Character default Constructor called" << std::endl;

	for (int i = 0; i < 4; i++) {
		
		this->_inventory[i] = NULL;
	}

	return ;
}

Character::Character( std::string const & name ) : _name(name) {

	std::cout << "Character with name " << name << " constructed" << std::endl;

	for (int i = 0; i < 4; i++) {
		
		this->_inventory[i] = NULL;
	}

	return ;
}

// Copy Constructor

Character::Character( Character const & src ) {

//	std::cout << "Character copy constructor called" << std::endl;

	*this = src ;

	return ;
}

// Copy assignment operator overload

Character &	Character::operator=( Character const & rhs ) {

	std::cout << "Copy assignement operator called" << std::endl;

	if (this != &rhs) {
		//deep copy
		for (int i = 0; i < 4; i++) {
			if (this->_inventory[i])
				delete this->_inventory[i];
			this->_inventory[i] = rhs._inventory[i]->clone();
		}
	}

	return *this ;
}

// Destructor

Character::~Character( void ) {

//	std::cout << "Character destructor called" << std::endl;

	for (int i = 0; i < 4; i++) {
		
		if (this->_inventory[i] != NULL) {
			delete this->_inventory[i];
			this->_inventory[i] = NULL;
		}
	}

	return ;
}

// Getter function

std::string const &	Character::getName( void ) const {

	return this->_name;
}

// Other member functions

// Materias are added to the first empty slot. If all four slots are full,
// the given materia (m) is not added.

void	Character::equip( AMateria* m ) {

	if (m == NULL)
		return ;
	for (int i = 0; i < 4; i++) {

		if (! _inventory[i]) {

				_inventory[i] = m;
				std::cout << _name << " now equipped with " << m->getType() << std::endl;
				return ;
		}
	}
	
	return ;
}

void	Character::unequip( int idx ) {

	if (idx < 0 || idx > 3)
		return ;
	
	_inventory[idx] = NULL;

	return ;
}

void	Character::use( int idx, ICharacter& target ) {

	if (idx >= 0 && idx < 4 && this->_inventory[idx]) 
		this->_inventory[idx]->use( target );

	else
		std::cout << "you are not equipped with this materia" << std::endl;
	
	return ;	
}


