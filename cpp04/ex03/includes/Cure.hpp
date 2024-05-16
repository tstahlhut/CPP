/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:14:23 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/15 14:51:57 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CURE_HPP_
# define _CURE_HPP_

#include "AMateria.hpp"

class Cure : public AMateria {

	public:
		Cure( void );									// Default constructor
		Cure( Cure const & src );						// Copy constructor
		Cure &	operator=( Cure const & rhs );
		~Cure( void );

		
		AMateria* 		clone( void ) const;
		virtual void	use( ICharacter & target );


};

#endif