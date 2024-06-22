/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:16:59 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/06/20 13:03:28 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PmergeMe_HPP
# define _PmergeMe_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <list>
# include <cctype>
# include <stdexcept>
# include <cstdlib>
# include <climits>
# include <algorithm>

class	PmergeMe {

	public:
		PmergeMe( void );								// Default constructor (can also be put into private if user should not be able to use it )
		PmergeMe( PmergeMe const & src );				// Copy constructor: a new instance is created
		PmergeMe &	operator=( PmergeMe const & rhs );	// Copy assignment operator overload
		~PmergeMe( void );								// Destuctor

		std::deque<unsigned int> const &	getDeque( void ) const;
		std::list<unsigned int> const &		getList( void ) const;
		std::vector<unsigned int> const &	getUnsortedSequence( void ) const;
		size_t const &						getLength( void ) const;

		void	addSequence( char ** sequence, int end ); //parses and adds sequence
		void	addNumber( char * number);				//adds a number to the unsorted sequence

		std::deque<unsigned int> const &	sortDeque( void );
		void	insertElement( unsigned int element);//, unsigned int end );

		bool	dequeIsSorted( void ) const;
		template<typename T>
		void	printSequence( T const & sequence, size_t const length );

		class WrongSymbolException : public std::exception {
			public:
			virtual const char*	what( void ) const throw()
			{
				return ("Error: Wrong input! Only positive integers allowed");
			}
		};

		class DuplicateException : public std::exception {
			public:
			virtual const char*	what( void ) const throw()
			{
				return ("Error: At least one duplicate");
			}
		};

	
	private:

		std::vector<unsigned int>	_unsortedSequence;
		std::deque<unsigned int>	_deque;
		std::list<unsigned int>		_list;
		size_t						_length;
};

std::ostream &	operator<<( std::ostream & o, PmergeMe const & rhs );

template<typename T>
void	PmergeMe::printSequence( T const & sequence, size_t const length ) {

	typename T::const_iterator	it = sequence.begin();
	
	if (sequence.empty()) {
		std::cout << "Sequence: empty" << std::endl;
		return ;
	}
	if (length > 20) {
		for (int i = 0; i < 20; i++)
			std::cout << *it++ << " ";
		std::cout << "[...]";
	}
	else {
		for (typename T::const_iterator it = sequence.begin(); it != sequence.end(); it++ )
			std::cout << *it << " ";
	}
	std::cout << std::endl;
	return ;
}



#endif