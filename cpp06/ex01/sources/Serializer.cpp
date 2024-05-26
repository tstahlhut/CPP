/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:24:38 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/15 16:10:18 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/Serializer.hpp"

// Default Constructor

Serializer::Serializer( void ) {

	std::cout << "Default Constructor called" << std::endl;

	return ;
}

// Copy Constructor

Serializer::Serializer( Serializer const & src ) {

	std::cout << "Copy Constructor called" << std::endl;

	*this = src ;

	return ;
}

// Copy assignment operator overload

Serializer &	Serializer::operator=( Serializer const & rhs ) {

	std::cout << "Copy assignement operator called" << std::endl;

	if (this == &rhs)
		return *this;

	return *this ;
}

// Destructor

Serializer::~Serializer( void ) {

	std::cout << "Destructor called" << std::endl;

	return ;
}

//It takes a pointer and converts it to the unsigned integer type uintptr_t.
uintptr_t	Serializer::serialize(Data* ptr) {

	return reinterpret_cast<uintptr_t>(ptr);
}

//It takes an unsigned integer parameter and converts it to a pointer to Data.
Data* 		Serializer::deserialize(uintptr_t raw) {

	return reinterpret_cast<Data*>(raw);
}