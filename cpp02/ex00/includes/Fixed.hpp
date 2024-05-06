/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:56:25 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/06 13:47:24 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FIXED_HPP
# define _FIXED_HPP

# include <iostream>

class Fixed
{

	public:
		Fixed( void ); //Default Constructor initializes fixed-point number value to 0.
		Fixed( const Fixed& other); //Copy Constructor
		// Copy assignment operator overloads
		// operator overloads:
		// Integer &	operator-( Integer const & rhs );
		// Integer		operator+( Integer const & rhs) const;
		~Fixed();	//Destructor

		int		getRawBits( void ) const; //returns the raw value of the fixed-point value
		void	setRawBits( int const raw ); // sets the raw value of the fixed-point number



	private:

		int	_fixedPointValue;
		static const int	_numBits; //A static constant integer to store the number of fractional bits. 
										//Its value will always be the integer literal 8.

};



#endif