/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:16:59 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/09 14:47:41 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// This is the header file for the ClapTrap Class

#ifndef _CLAPTRAP_HPP
# define _CLAPTRAP_HPP

# include <string>
# include <iostream>

class	ClapTrap {

	public:
		ClapTrap( std::string name );					// Constructor
		ClapTrap( ClapTrap const & src );				// Copy constructor
		ClapTrap &	operator=( ClapTrap const & rhs );	// Copy assignment operator
		~ClapTrap( void );								// Destuctor
	
		std::string		getName( void ) const;
		unsigned int	getHitPoints( void ) const;
		unsigned int	getEnergyPoints( void ) const;
		unsigned int	getAttackDamage( void ) const;

		void	attack( const std::string& target );
		void	takeDamage( unsigned int amount );
		void	beRepaired( unsigned int amount );


	private:

		ClapTrap( void ); 								// Default constructor ( user should not be able to use it )

		std::string		_name;
		unsigned int	_hitPoints;	// health
		unsigned int	_energyPoints;	// Energy Points
		unsigned int	_attackDamage;	// Attack Damage
};


#endif