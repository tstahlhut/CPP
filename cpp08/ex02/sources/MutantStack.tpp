/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:15:13 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/06/13 10:51:36 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MutantStack.hpp"

//Default constructor 
template< typename T, typename C >
MutantStack<T, C>::MutantStack( void ) : std::stack<T, C>() {

	//std::cout << "Default Constructor called" << std::endl;

	return ;
}

//Copy Constructor
template< typename T, typename C >
MutantStack<T, C>::MutantStack( MutantStack const & src ) : std::stack<T, C>(src) {

//	std::cout << "Copy Constructor called" << std::endl;

	return ;
}

//Destructor
template< typename T, typename C >
MutantStack<T, C>::~MutantStack( void ) {

//	std::cout << "Destructor called" << std::endl;

	return ;
}


// Copy assignment operator overload
template< typename T, typename C >
MutantStack<T, C> &	MutantStack<T, C>::operator=( MutantStack const & rhs ) {

//	std::cout << "Copy assignement operator called" << std::endl;

	if (this != &rhs) {

		std::stack<T, C>::operator=(rhs);
	
	}

	return *this ;
}

//Iterators

template< typename T, typename C >
typename MutantStack< T, C >::iterator	MutantStack< T, C>::begin() {

	return this->c.begin();
}

template< typename T, typename C>
typename MutantStack< T, C >::iterator	MutantStack< T, C >::end() {
	return this->c.end();
}

//returns reverse iterator to reverse beginning
template< typename T, typename C >
typename MutantStack< T, C >::reverse_iterator	MutantStack< T, C>::rbegin() {

	return this->c.rbegin();
}
//returns reverse iterator to reverse end	
template< typename T, typename C >
typename MutantStack< T, C >::reverse_iterator	MutantStack< T, C>::rend() {

	return this->c.rend();
}	


//returns const_iterator to beginning	(it can iterate but values cannot be modified)
template< typename T, typename C >
typename MutantStack< T, C >::const_iterator	MutantStack< T, C>::cbegin() const {

	return this->c.begin();
}

//returns const_iterator to end	(it can iterate but values cannot be modified)
template< typename T, typename C >
typename MutantStack< T, C >::const_iterator	MutantStack< T, C>::cend() const {

	return this->c.end();
}


//returns const_reverse_iterator to reverse beginning (it can iterate but values cannot be modified)
template< typename T, typename C >
typename MutantStack< T, C >::const_reverse_iterator	MutantStack< T, C>::crbegin() const {

	return this->c.rbegin();
}

//returns const_reverse_iterator to reverse end (it can iterate but values cannot be modified)
template< typename T, typename C >
typename MutantStack< T, C >::const_reverse_iterator	MutantStack< T, C>::crend() const {

	return this->c.rend();
}	
	



