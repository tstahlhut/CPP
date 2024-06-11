/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:51:58 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/06/11 18:27:21 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _EASYFIND_HPP_
# define _EASYFIND_HPP_

# include <algorithm>
# include <stdexcept>

template< typename T >
typename T::const_iterator easyfind( T const & container, int const find ) {

	typename T::const_iterator	it = std::find( container.begin(), container.end(), find );
	
	if (it == container.end())
		throw std::out_of_range("Value not found in container");

	return it;
	
}

#endif