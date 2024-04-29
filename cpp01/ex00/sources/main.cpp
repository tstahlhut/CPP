/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:18:35 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/04/29 17:31:01 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main( void )
{
	randomChump("Foo");

	Zombie *WalkingDead = newZombie("WalkingDead");

	WalkingDead->announce();
	WalkingDead->announce();
	WalkingDead->announce();
	delete WalkingDead;

	return 0;
}