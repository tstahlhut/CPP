/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:07:27 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/04/30 14:50:56 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _HARL_H
# define _HARL_H

# include <iostream>
# include <string>

class Harl
{
	public:
		Harl( void );	//Default Constructor
		~Harl( void );	//Destructor

		void	complain( std::string level );

	private:
		void	debug( void );
		void	info( void );
		void	warning( void );
		void	error( void );
};



#endif