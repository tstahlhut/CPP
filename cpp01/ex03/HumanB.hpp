/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:40:22 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/03/11 17:49:59 by tstahlhu         ###   ########.fr       */
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

	Weapon*	weapon;
	void	setWeapon( Weapon weapon );

	void	attack( void );

	private:

	std::string	_name;
};

#endif