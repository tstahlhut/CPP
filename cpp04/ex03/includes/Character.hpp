/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:00:51 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/15 16:59:40 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CHARACTER_HPP_
# define _CHARACTER_HPP_

# include "ICharacter.hpp"

class Character : public ICharacter {

	public:
		Character( void );
		Character( std::string const & name );
		Character( Character const & src );
		Character&	operator=( Character const & rhs );
		~Character( void );
		
		std::string const &	getName( void ) const;

		void			equip( AMateria* m );
		void			unequip( int idx );
		virtual void	use( int idx, ICharacter & target );

	private:
		std::string	_name;
		AMateria*	_inventory[4];
};

#endif