/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:14:23 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/15 17:01:46 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _AMATERIA_HPP_
# define _AMATERIA_HPP_

# include <iostream>
# include <string>
# include "ICharacter.hpp"

class ICharacter; // do not forget to include ICharacter class!

class AMateria {

	public:
		AMateria( void );
		AMateria( std::string const & type );
		virtual ~AMateria( void );

		std::string const & getType( void ) const; 		// returns the materia type

		virtual AMateria* 	clone( void ) const = 0;	// pure virtual function
		virtual void		use( ICharacter & target );

	protected:

		std::string const	_type;

};

#endif