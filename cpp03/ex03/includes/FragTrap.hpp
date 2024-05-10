/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:40:10 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/10 15:12:37 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FRAGTRAP_HPP
# define _FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap				// virtual inheritance solves Diamond problem
{
	public:
		FragTrap( std::string name );					// Constructor
		FragTrap( FragTrap const & src );				// Copy constructor
		FragTrap &	operator=( FragTrap const & rhs );	// Copy assignment operator
		~FragTrap( void );								// Destuctor

		void	highFivesGuys( void );

	protected:
		FragTrap( void );								// Default Constructor
};


#endif