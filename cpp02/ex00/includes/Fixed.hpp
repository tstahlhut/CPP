/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:56:25 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/08 14:13:52 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FIXED_HPP
# define _FIXED_HPP

# include <iostream>

class Fixed
{

	public:
		Fixed( void ); //Default Constructor initializes fixed-point number value to 0.
		Fixed( const Fixed & src ); //Copy Constructor
		~Fixed();	//Destructor

		Fixed &	operator=( Fixed const & rhs ); // Copy assignment operator overloads

		int		getRawBits( void ) const; //returns the raw value of the fixed-point value
		void	setRawBits( int const raw ); // sets the raw value of the fixed-point number



	private:

		int					_raw;
		static const int	_fractionalBits; //A static constant integer to store the number of fractional bits. 
										//Its value will always be the integer literal 8.

};



#endif