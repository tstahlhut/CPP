/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:04:26 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/26 15:45:30 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _SCALARCONVERTER_HPP
# define _SCALARCONVERTER_HPP

# include <iostream>
# include <sstream> // for istringstream
# include <cctype>	// for isprint
# include <iomanip> // for setprecision ( to print floats and doubles )
# include <limits>	// for numeric_limits ( length of doubles and floats )
# include <climits> // macros for max and min limits of fundamental integral types
# include <cfloat> 	// macros for max and min limits of floating-point types

class	ScalarConverter {

	private:
		ScalarConverter( void );										// Default constructor (can also be put into private if user should not be able to use it )
		ScalarConverter( ScalarConverter const & src );					// Copy constructor: a new instance is created
		ScalarConverter &	operator=( ScalarConverter const & rhs );	// Copy assignment operator overload
		~ScalarConverter( void );										// Destuctor

	public:

		static void		convert( std::string literal );

};

/* The Constructors are private so that the class is not instantiable.
 Because the convert functions are static, we can still call and use them in 
 our main program.*/

bool	isChar( std::string	literal, int *	intOutOfRange );
bool	isInt( std::string	literal, int *	intOutOfRange );
bool	isDouble( std::string	literal, int * outOfRange );
bool	isFloat( std::string	literal, int *	intOutOfRange );
bool	specialCase( std::string literal );

void	printValues( int outOfRange, char c, int i, float f, double d );

#endif