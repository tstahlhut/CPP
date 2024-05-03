/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:33:26 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/02 11:23:30 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H

# include <string>
# include <iostream>

class	Weapon
{
	public:

		Weapon( void );
		Weapon( std::string type );
		~Weapon( void );

		std::string	getType( void ) const;
		void	setType( std::string type);

	private:

		std::string	_type;

};


#endif