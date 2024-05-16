/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:00:51 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/16 11:24:32 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ICHARACTER_HPP_
# define _ICHARACTER_HPP_

# include <string>
# include "AMateria.hpp"

class AMateria;

class ICharacter {

	public:
		virtual ~ICharacter( void ) {}
		
		virtual std::string const &	getName( void ) const = 0;

		virtual void	equip( AMateria* m ) = 0;
		virtual void	unequip( int idx ) = 0;
		virtual void	use( int idx, ICharacter & target ) = 0;
};

#endif

/* NOTE: We do not need any .cpp file for this interface class as we do not implement any of the functions.
		However, the destructor has to be implemented. But this can be done by adding empty brackets{}.*/