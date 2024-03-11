/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:18:35 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/03/11 13:47:27 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main( void )
{
	randomChump("Foo");

	Zombie *WalkingDead = newZombie("WalkingDead");

	WalkingDead->announce();

	delete WalkingDead;

	return 0;
}