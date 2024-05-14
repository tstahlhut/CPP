/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:16:59 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/14 14:38:01 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef _ANIMAL_HPP
# define _ANIMAL_HPP

# include <string>
# include <iostream>

class	Animal {

	public:
		Animal( void );									// Default constructor
		Animal( Animal const & src );					// Copy constructor
		Animal &	operator=( Animal const & rhs );	// Copy assignment operator
		virtual ~Animal( void );						// Destuctor: virtual (otherwise Dog or Cat Destructor would not be called)
	
		std::string	getType( void ) const;

		virtual void	makeSound( void ) const;

	protected:
		std::string	_type;

};


#endif