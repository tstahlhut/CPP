/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:54:25 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/15 16:38:00 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MATERIASOURCE_HPP_
# define _MATERIASOURCE_HPP_

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {

	public:
		MateriaSource( void );
		MateriaSource( MateriaSource const & src );
		MateriaSource &	operator=( MateriaSource const & rhs );
		~MateriaSource( void );
		
		void		learnMateria( AMateria* m);
		AMateria*	createMateria( std::string const & type );

	private:
		AMateria*	_materias[4];

};

#endif