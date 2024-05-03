/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:18:55 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/03 12:43:41 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <iostream>

class	Zombie
{
	public:

		Zombie ( void );		// Default Constructor
		Zombie ( std::string name ); // Constructor
		~Zombie ( void );	//Destructor

		void	announce( void );
		void	setName( std::string name );

	private:

		std::string	_name;

};

Zombie*	zombieHorde( int N, std::string name );

#endif