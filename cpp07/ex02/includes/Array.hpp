/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 17:53:02 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/08/22 13:00:54 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ARRAY_HPP_
# define _ARRAY_HPP_

# include <iostream>
# include <stdexcept>
# include <string>

template< typename T >
class	Array {

	public:
		Array( void );
		Array( unsigned int n );
		Array( Array const & src );
		~Array( void );

		Array<T> &	operator=( Array const & rhs );
		T &			operator[]( unsigned int n );
		T const &	operator[]( unsigned int const n ) const;

		unsigned int	size( void ) const;


	private:
		T *				_array;
		unsigned int	_size;
};

template< typename T >
std::ostream &	operator<<( std::ostream & o, Array<T> const & a );

#endif