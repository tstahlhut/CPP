/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:56:25 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/07 11:06:11 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FIXED_HPP
# define _FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{

	public:
		// Constructors and Destructor
		Fixed( void );				// Default Constructor initializes fixed-point number value to 0.
		Fixed( const int i );		// Constructor (int)
		Fixed( const float f ); 	// Constructor: converts float to fixed-point value
		Fixed( const Fixed & src ); // Copy Constructor
		~Fixed();					// Destructor

		Fixed &	operator=( Fixed const & rhs ); // Copy assignment operator overloads
		
		int		getRawBits( void ) const; //returns the raw value of the fixed-point value
		void	setRawBits( int const raw ); // sets the raw value of the fixed-point number

		float	toFloat( void ) const;		// converts fixed-point value to floating-point value
		int		toInt( void ) const;		// converts fixed-point value to integer value

	private:

		int					_raw;			// fixed-point value
		static const int	_fractionalBits; //A static constant integer to store the number of fractional bits. 
										//Its value will always be the integer literal 8.
};

std::ostream &	operator<<( std::ostream & o, Fixed const & rhs );

#endif