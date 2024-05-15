/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:16:59 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/15 14:14:53 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef _AANIMAL_HPP
# define _AANIMAL_HPP

# include <string>
# include <iostream>

class	AAnimal {

	public:
		AAnimal( void );									// Default constructor
		AAnimal( AAnimal const & src );					// Copy constructor
		AAnimal &	operator=( AAnimal const & rhs );	// Copy assignment operator
		virtual ~AAnimal( void );						// Destuctor: virtual (otherwise Dog or Cat Destructor would not be called)
	
		virtual std::string	getType( void ) const;

		virtual void	makeSound( void ) const = 0;	// pure virtual function

	protected:
		std::string	_type;

};


#endif