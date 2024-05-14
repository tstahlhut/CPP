/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 17:09:52 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/14 15:13:04 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Brain.hpp"

// Default Constructor

Brain::Brain( void ) {

	std::cout << "Default Brain Constructor called" << std::endl;

	return ;
}

// Copy Constructor

Brain::Brain( Brain const & src ) {

	std::cout << "Copy Brain Constructor called" << std::endl;

	*this = src ;

	return ;
}

// Destructor

Brain::~Brain( void ) {

	std::cout << "Brain Destructor called" << std::endl;

	return ;
}

// Copy assignment operator overload

Brain &	Brain::operator=( Brain const & rhs ) {

	std::cout << "Brain Copy assignement operator called" << std::endl;

	if (this != &rhs) {

		for (int i = 0; i < 100; i++)
			this->_ideas[i] = rhs.getIdeas(i);
	}

	return *this ;
}


// Getter

std::string	Brain::getIdeas( int index ) const {

	if (index < 0 || index > 100 || this->_ideas[index].empty())
		return NULL;
	return this->_ideas[index];
}

// Setter

void		Brain::setIdeas( std::string const newIdea) {

	int	i = 0;
	while (i < 100 && !this->_ideas[i].empty())
		i++;
	if (i == 100)
		std::cout << "Brain capacity reached: No space for new ideas!" << std::endl;	
	this->_ideas[i] = newIdea;

	return ;
}
