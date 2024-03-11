/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:39:20 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/03/11 17:52:18 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_H
# define HUMAN_A_H

# include "Weapon.hpp"

class	HumanA
{
	public:

	HumanA( std::string name, std::string weapon );
	~HumanA( void );

	Weapon weapon;

	void	attack( void );

	private:

	std::string	_name;
};

#endif