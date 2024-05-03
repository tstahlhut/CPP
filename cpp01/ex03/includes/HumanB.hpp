/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:40:22 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/02 11:23:12 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B_H
# define HUMAN_B_H

# include "Weapon.hpp"

class	HumanB
{
	public:

		HumanB( std::string name );
		~HumanB( void );

		void	setWeapon( Weapon& weapon );
		void	attack( void );

	private:

		std::string const	_name;
		Weapon*		_weapon;
};

#endif