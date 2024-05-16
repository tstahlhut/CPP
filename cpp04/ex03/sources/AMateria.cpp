/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:14:23 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/16 11:25:43 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AMateria.hpp"

AMateria::AMateria( void ) {

//	std::cout << "AMateria default constructor called" << std::endl;

	return ;
}


AMateria::AMateria( std::string const & type ) : _type(type) {

//	std::cout << "AMateria constructor called" << std::endl;

	return ;
}


AMateria::~AMateria( void ) {

//	std::cout << "AMateria destructor called" << std::endl;

	return ;
}


// Getter: returns the materia type

std::string const & AMateria::getType( void ) const {

	return this->_type;
} 

void		AMateria::use( ICharacter& target ) {

	std::cout << "* uses some materia on " << target.getName() << " *" << std::endl;

}
