/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:39:20 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/02 11:22:37 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_H
# define HUMAN_A_H

# include "Weapon.hpp"

class	HumanA
{
	public:

		HumanA( std::string const name, Weapon const & someWeapon );
		~HumanA( void );

		void	attack( void );
	
	private:
		std::string	const _name;
		Weapon const &	_weapon;

};

#endif