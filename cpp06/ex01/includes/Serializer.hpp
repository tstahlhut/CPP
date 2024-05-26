/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:04:26 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/26 14:53:51 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _SERIALIZER_HPP
# define _SERIALIZER_HPP

# include <iostream>
# include <stdint.h> // for uintptr_t
# include "Data.hpp"

struct Data;

class	Serializer {

	private:
		Serializer( void );										// Default constructor (can also be put into private if user should not be able to use it )
		Serializer( Serializer const & src );					// Copy constructor: a new instance is created
		Serializer &	operator=( Serializer const & rhs );	// Copy assignment operator overload
		~Serializer( void );									// Destuctor

	public:

		static uintptr_t	serialize(Data* ptr);
		static Data* 		deserialize(uintptr_t raw);

};

/* The Constructors are private so that the class is not initializable.
 Because the functions are static, we can still call and use them in 
 our main program.*/


#endif