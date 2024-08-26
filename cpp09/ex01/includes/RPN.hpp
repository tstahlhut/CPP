/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:16:59 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/06/12 15:18:22 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _RPN_HPP
# define _RPN_HPP

# include <iostream>
# include <stack>
# include <cctype>
# include <stdexcept>

class	RPN {

	public:
		RPN( void );
		RPN( RPN const & src );
		RPN &	operator=( RPN const & rhs );
		~RPN( void );

		std::stack<int>	getStack( void ) const;

		void	put( char c);
		void	put( int n );

		class WrongSymbolException : public std::exception {
			public:
			virtual const char*	what( void ) const throw()
			{
				return ("Error: Wrong symbol");
			}
		};

		class SyntaxErrorException : public std::exception {
			public:
			virtual const char*	what( void ) const throw()
			{
				return ("Error: Syntax Error");
			}
		};

	
	private:
		std::stack<int>	_stack;

		int	getOperand( void );
};

std::ostream &	operator<<( std::ostream & o, RPN const & rhs );


#endif