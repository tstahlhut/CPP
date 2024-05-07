/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:56:25 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/07 14:04:13 by tstahlhu         ###   ########.fr       */
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
		
		// Comparison operators
		bool	operator>( Fixed const & rhs) const;
		bool	operator<( Fixed const & rhs) const;
		bool	operator>=( Fixed const & rhs) const;
		bool	operator<=( Fixed const & rhs) const;
		bool	operator==( Fixed const & rhs) const;
		bool	operator!=( Fixed const & rhs) const;
		
		// Arithmetic operators
		Fixed	operator+( Fixed const & rhs ) const;
		Fixed	operator-( Fixed const & rhs ) const;
		Fixed	operator*( Fixed const & rhs ) const;
		Fixed	operator/( Fixed const & rhs ) const;

		// Increment & decrement operators
		Fixed &	operator++( void );
		Fixed	operator++( int );
		Fixed &	operator--( void );
		Fixed	operator--( int );
		
		// min & max overload functions ( if not static it can only be used with a specific object )
		static Fixed &			min( Fixed & lhs, Fixed & rhs);
		static Fixed const &	min( Fixed const & lhs, Fixed const & rhs);
		static Fixed &			max( Fixed & lhs, Fixed & rhs);
		static Fixed const &	max( Fixed const & lhs, Fixed const & rhs);

		// getter & setter functions
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