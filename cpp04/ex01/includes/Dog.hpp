/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:16:59 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/11 16:34:50 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef _DOG_HPP
# define _DOG_HPP

# include "Animal.hpp"
# include <iostream>
# include <string>

class	Dog : public Animal {

	public:
		Dog( void );							// Default constructor
		Dog( Dog const & src );					// Copy constructor
		Dog &	operator=( Dog const & rhs );	// Copy assignment operator
		~Dog( void );							// Destuctor

		virtual void	makeSound( void ) const;
};


#endif