/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 17:53:02 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/06/08 18:46:30 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ITER_HPP_
# define _ITER_HPP_

template< typename T, typename F >
void iter( T * array, int length, F function ) {

	for( int i = 0; i < length; i++) {
		function(array[i]);
	}
}

#endif