/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:16:59 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/15 12:40:26 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef _CAT_HPP
# define _CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"
# include <iostream>
# include <string>

class	Cat : public AAnimal {

	public:
		Cat( void );							// Default constructor
		Cat( Cat const & src );					// Copy constructor
		Cat &	operator=( Cat const & rhs );	// Copy assignment operator
		~Cat( void );							// Destuctor

		Brain*	getBrain( void ) const;			// Getter function

		virtual void	makeSound( void ) const;

	private:
		Brain*	_brain;

};


#endif