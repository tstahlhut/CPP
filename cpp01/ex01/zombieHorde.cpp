/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:32:41 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/03/11 15:31:51 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde( int n, std::string name )
{
	if (n <= 0)
		return (NULL);

	Zombie*	horde = new Zombie[n];

	for( int i = 0; i < n; i++)
	{
		horde[i].setName( name );
	}

	return horde;	
}