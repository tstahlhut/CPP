/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 17:53:02 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/06/08 18:12:18 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _WHATEVER_HPP_
# define _WHATEVER_HPP_

template< typename T >
void swap( T & x, T & y ) {

	T	temp;

	temp = x;
	x = y;
	y = temp;
}

template< typename T >
T const &	min( T const & x, T const & y ) {
	return (x<y ? x : y );
}

template< typename T >
T const &	max( T const & x, T const & y ) {
	return (x>y ? x : y );
}

#endif