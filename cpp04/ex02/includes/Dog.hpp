/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:16:59 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/15 12:40:18 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef _DOG_HPP
# define _DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"
# include <iostream>
# include <string>

class	Dog : public AAnimal {

	public:
		Dog( void );							// Default constructor
		Dog( Dog const & src );					// Copy constructor
		Dog &	operator=( Dog const & rhs );	// Copy assignment operator
		~Dog( void );							// Destuctor

		Brain*	getBrain( void ) const;			// Getter

		virtual void	makeSound( void ) const;

	private:
		Brain*	_brain;

};

#endif