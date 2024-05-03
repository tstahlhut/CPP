/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:07:27 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/02 11:34:28 by tstahlhu         ###   ########.fr       */
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

		void	_debug( void );
		void	_info( void );
		void	_warning( void );
		void	_error( void );
};



#endif