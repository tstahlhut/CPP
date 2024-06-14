/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:13:46 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/06/14 12:59:44 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MUTANTSTACK_HPP_
# define _MUTANTSTACK_HPP_

# include <iostream>
# include <stack>
# include <deque>
# include <algorithm>
# include <iterator>


template< typename T, typename C = std::deque<T> >					//template< typename T, class Container = std::deque<T> >
class MutantStack : public std::stack< T, C > {

	public:
		MutantStack( void );
		MutantStack( MutantStack const & src );
		~MutantStack( void );

		MutantStack &	operator=( MutantStack const & rhs );

		
		typedef typename C::iterator				iterator;			//typedef typename std::stack< T, C >::container_type::iterator	iterator;
		typedef typename C::reverse_iterator		reverse_iterator;
		typedef typename C::const_iterator			const_iterator;
		typedef typename C::const_reverse_iterator	const_reverse_iterator;

		iterator				begin();		//returns iterator to beginning
		iterator				end();			//returns iterator to end
		reverse_iterator		rbegin();		//returns reverse iterator to reverse beginning
		reverse_iterator		rend();			//returns reverse iterator to reverse end
		const_iterator			cbegin() const;	//returns const_iterator to beginning
		const_iterator			cend() const;	//returns const_iterator to end
		const_reverse_iterator	crbegin() const;//returns const_reverse_iterator to reverse beginning
		const_reverse_iterator	crend() const;	//returns const_reverse_iterator to reverse end
	
};



#endif