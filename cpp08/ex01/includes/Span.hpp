/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:13:46 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/06/13 09:39:14 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _SPAN_HPP_
# define _SPAN_HPP_

# include <iostream>
# include <deque>
# include <algorithm>
# include <stdexcept>
# include <iterator>

class Span {

	public:
		Span( unsigned int N );
		Span( Span const & src );
		~Span( void );

		Span &	operator=( Span const & rhs );

		std::deque<int> const &	getArray( void ) const;

	//	template< typename T = int > // default type: int
	//	void	addNumber( T & num );
		void	addNumber( int N );
		void	addRange( std::deque<int>::const_iterator first, std::deque<int>::const_iterator last );

		unsigned int	shortestSpan( void );
		unsigned int	longestSpan( void ) const;

		class	RangeTooSmall : public std::exception {
			public:
				virtual const char *	what( void ) const throw();
		};

	private:
		Span( void );

	//	template< typename T = int >
	//	std::deque<T>		_array;
		std::deque<int>		_array;

		unsigned int	_capacity;
};

std::ostream &	operator<<( std::ostream & o, Span const & rhs );


#endif