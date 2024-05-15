/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:54:25 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/15 17:15:22 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _IMATERIASOURCE_HPP_
# define _IMATERIASOURCE_HPP_

# include "AMateria.hpp"

class IMateriaSource {

	public:
		virtual ~IMateriaSource( void ) {};	
		
		virtual	void		learnMateria( AMateria* ) = 0;
		virtual AMateria*	createMateria( std::string const & type ) = 0;

};

#endif

/* NOTE: We do not need any .cpp file for this interface class as we do not implement any of the functions.
		However, the destructor has to be implemented. But this can be done by adding empty brackets{}.*/