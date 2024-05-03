/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:07:59 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/03 13:20:55 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

//Default Constructor
Harl::Harl( void )
{
	//std::cout << "Hi I am Harl and I love Sahara!" << std::endl;
	//std::cout << "So much that I am more than ready to complain ..." << std::endl;
	return ;
}

//Destructor
Harl::~Harl( void )
{
	//std::cout << "This is enough. I will leave you now." << std::endl;
	return ;
}

void	Harl::complain( std::string level )
{
	//array of pointers to member functions
	void	(Harl::*FunctionPointer[4])( void ) = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};

	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4; i++)	
	{
		if (levels[i] == level) 
		{
			(this->*FunctionPointer[i])();
			return ;
		}
	}
	std::cerr << "Unknown level: " << level << std::endl;	
	return ;
}

void	Harl::_debug( void )
{
	std::cout << "I love having extra peanut sauce on my Sahara sandwich. I really do!" << std::endl;
	return ;
}

void	Harl::_info( void )
{
	std::cout << "This is not the level of peanut sauce I meant. It should be more." << std::endl;
	return ;
}

void	Harl::_warning( void )
{
	std::cout << "I think I deserve more peanut sauce. Otherwise, I take back the tip." << std::endl;
	return ;
}

void	Harl::_error( void )
{
	std::cout << "This is unacceptable! I want to speak to the owner now." << std::endl;
	return ;
}