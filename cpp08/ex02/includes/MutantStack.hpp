/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:13:46 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/06/13 12:23:39 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MUTANTSTACK_HPP_
# define _MUTANTSTACK_HPP_

# include <iostream>
# include <stack>
# include <deque>
# include <algorithm>
//# include <stdexcept>
# include <iterator>

//template< typename T, class Container = std::deque<T> >
template< typename T, typename C = std::deque<T> >
class MutantStack : public std::stack< T, C > {

	public:
		MutantStack( void );
		MutantStack( MutantStack const & src );
		~MutantStack( void );

		MutantStack &	operator=( MutantStack const & rhs );

		typedef typename std::stack< T, C >::container_type::iterator	iterator;
	//	typedef typename C::iterator	it;

		iterator	begin();
		iterator	end();

	
};



#endif