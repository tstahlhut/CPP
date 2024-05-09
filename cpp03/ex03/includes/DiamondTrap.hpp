/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:30:41 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/09 16:00:20 by tstahlhu         ###   ########.fr       */
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

		void	whoAmI();
		//attack function should be inherited from ScavTrap

	private:
		DiamondTrap( void );								// Default Constructor

		std::string	_name;
};


#endif