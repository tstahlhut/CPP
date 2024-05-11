/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:16:59 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/11 16:34:50 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef _WRONGCAT_HPP
# define _WRONGCAT_HPP

# include "WrongAnimal.hpp"
# include <iostream>
# include <string>

class	WrongCat : public WrongAnimal {

	public:
		WrongCat( void );							// Default constructor
		WrongCat( WrongCat const & src );					// Copy constructor
		WrongCat &	operator=( WrongCat const & rhs );	// Copy assignment operator
		~WrongCat( void );							// Destuctor

		void	makeSound( void ) const;
};


#endif