/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:07:59 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/04/30 14:42:40 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

//Default Constructor
Harl::Harl( void )
{
	std::cout << "Constructor called" << std::endl;
	return ;
}

//Destructor
Harl::~Harl( void )
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

void	Harl::complain( std::string level )
{
	Harl	instance;
	void	(Harl::*f)( void );

	if (level != "debug" && level != "info" && level != "warning" && level != "error")
	{
		std::cout << "I love to complain! But this level is unknown to me." << std::endl;
		return ;
	}
//	f = &Harl::debug;
	//(instance.*f());
	return ;
}

void	Harl::debug( void )
{
	std::cout << "I love having extra peanut sauce on my Sahara sandwich. I really do!" << std::endl;
	return ;
}

void	Harl::info( void )
{
	std::cout << "This is not the level of peanut sauce I meant. It should be more." << std::endl;
	return ;
}

void	Harl::warning( void )
{
	std::cout << "I think I deserve more peanut sauce. Otherwise, I take back the tip." << std::endl;
	return ;
}

void	Harl::error( void )
{
	std::cout << "This is unacceptable! I want to speak to the owner now." << std::endl;
	return ;
}