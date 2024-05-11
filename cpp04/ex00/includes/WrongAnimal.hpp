/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:16:59 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/11 17:06:33 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef _WRONGANIMAL_HPP
# define _WRONGANIMAL_HPP

# include <string>
# include <iostream>

class	WrongAnimal {

	public:
		WrongAnimal( void );									// Default constructor
		WrongAnimal( WrongAnimal const & src );					// Copy constructor
		WrongAnimal &	operator=( WrongAnimal const & rhs );	// Copy assignment operator
		~WrongAnimal( void );								// Destuctor
	
		std::string	getType( void ) const;

		void	makeSound( void ) const;

	protected:
		std::string	_type;

};


#endif