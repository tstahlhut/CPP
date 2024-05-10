/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:41:59 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/10 15:02:33 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _SCAVTRAP_HPP
# define _SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public:
		ScavTrap( std::string name );
		ScavTrap( ScavTrap const & src );	// Copy constructor
		~ScavTrap( void );					// Destuctor

		ScavTrap &	operator=( ScavTrap const & rhs ); // Copy assignment operator
	
		void	attack( const std::string& target );
		void	guardGate( void );

	protected:
		ScavTrap( void );	// Default Constructor
};


#endif