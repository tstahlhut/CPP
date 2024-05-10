/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:30:41 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/10 17:58:29 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _DIAMONDTRAP_HPP
# define _DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	public:
		DiamondTrap( std::string name );					// Constructor
		DiamondTrap( DiamondTrap const & src );				// Copy constructor
		DiamondTrap &	operator=( DiamondTrap const & rhs );	// Copy assignment operator
		~DiamondTrap( void );								// Destuctor

		using 	ScavTrap::attack;							// using keyword defines which inherited attack function should be used (Scav or Frag)
		
		void	whoAmI( void );

	private:
		DiamondTrap( void );								// Default Constructor

		std::string	_name;
		using ScavTrap::_energyPoints;
};


#endif