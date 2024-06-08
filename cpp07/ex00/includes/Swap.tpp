/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Swap.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 17:33:39 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/06/08 17:49:20 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _SWAP_TPP_
# define _SWAP_TPP_

template< typename T >

void swap( T & x, T & y ) {

	T	temp;

	temp = x;
	x = y;
	y = temp;
}

#endif