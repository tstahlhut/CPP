/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:11:01 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/16 11:28:33 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MateriaSource.hpp"

// Default Constructor

MateriaSource::MateriaSource( void ) {

//	std::cout << "MateriaSource default constructor called" << std::endl;

	for (int i = 0; i < 4; i++)
		this->_materias[i] = NULL;

	return ;
}

// Copy Constructor

MateriaSource::MateriaSource( MateriaSource const & src ) {

//	std::cout << "MateriaSource copy constructor called" << std::endl;

	*this = src ;

	return ;
}

// Copy assignment operator overload

MateriaSource &	MateriaSource::operator=( MateriaSource const & rhs ) {

//	std::cout << "MateriaSource copy assignement operator called" << std::endl;

	if (this != &rhs) {
		// deep copy
		for (int i = 0; i < 4; i++) {
			if (this->_materias[i])
				delete this->_materias[i];
			this->_materias[i] = rhs._materias[i]->clone();
		}
	}

	return *this ;
}

// Destructor

MateriaSource::~MateriaSource( void ) {

//	std::cout << "MateriaSource destructor called" << std::endl;

	for (int i = 0; i < 4; i++) {
		
		if (this->_materias[i])
			delete this->_materias[i];
	}

	return ;
}

// Member Functions

void		MateriaSource::learnMateria( AMateria* m) {

	for (int i = 0; i < 4; i++) {
		if (!this->_materias[i]) {
			this->_materias[i] = m;
			return ;
		}
	}
	delete m; // to avoid memory leaks, if "src->learnMateria(new Ice());"
	return ;
}


AMateria*	MateriaSource::createMateria( std::string const & type ) {

	int	i = 0;

	while (i < 4 && this->_materias[i]) {
		if (this->_materias[i]->getType() == type)
			return this->_materias[i]->clone();
		i++;
	}
	std::cout << "The materia " << type << " is unknown to me. I have to learn it first." << std::endl;
	return NULL;
}
