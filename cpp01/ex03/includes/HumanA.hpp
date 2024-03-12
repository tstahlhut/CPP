/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:39:20 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/03/12 17:43:04 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_H
# define HUMAN_A_H

# include "Weapon.hpp"

class	HumanA
{
	private:
		std::string	const _name;
		Weapon const &	_weapon;

	public:

		HumanA( std::string const name, Weapon const & someWeapon );
		~HumanA( void );

		void	attack( void );
};

#endif