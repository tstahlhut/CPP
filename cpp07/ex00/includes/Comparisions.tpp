/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Comparisions.tpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 17:53:02 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/06/08 17:55:53 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _COMPARISIONS_TPP_
# define _COMPARISIONS_TPP_

template< typename T >
T const &	min( T const & x, T const & y ) {
	return (x<y ? x : y );
}

template< typename T >
T const &	max( T const & x, T const & y ) {
	return (x>y ? x : y );
}

#endif