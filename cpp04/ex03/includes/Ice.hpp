/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:14:23 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/15 17:00:00 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ICE_HPP_
# define _ICE_HPP_

#include "AMateria.hpp"

class Ice : public AMateria {

	public:
		Ice( void );									// Default constructor
		Ice( Ice const & src );							// Copy constructor
		Ice &	operator=( Ice const & rhs );
		~Ice( void );

		
		AMateria* 		clone( void ) const;
		virtual void	use( ICharacter & target );


};

#endif