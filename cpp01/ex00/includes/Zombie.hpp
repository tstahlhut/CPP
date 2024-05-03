/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:18:55 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/03 12:43:01 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <iostream>

class	Zombie
{
	public:

		Zombie ( void );	//Constructor
		Zombie ( std::string name );
		~Zombie ( void );	//Destructor

		void	announce( void );

	private:

		std::string	_name;

};

void	randomChump( std::string name);
Zombie*	newZombie( std::string name );


#endif