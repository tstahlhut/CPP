/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:33:26 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/03/11 17:53:22 by tstahlhu         ###   ########.fr       */
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