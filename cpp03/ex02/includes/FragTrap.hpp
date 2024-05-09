/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:40:10 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/09 14:42:09 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FRAGTRAP_HPP
# define _FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap( std::string name );
		FragTrap( FragTrap const & src );	// Copy constructor
		~FragTrap( void );					// Destuctor

		FragTrap &	operator=( FragTrap const & rhs ); // Copy assignment operator

		void	highFivesGuys( void );
	private:
		FragTrap( void );	// Default Constructor
};


#endif