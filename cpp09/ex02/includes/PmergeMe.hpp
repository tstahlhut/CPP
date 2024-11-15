/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:16:59 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/11/15 11:18:25 by tstahlhu         ###   ########.fr       */
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
# include <ctime>

class	PmergeMe {

	public:
		//Constructors
		PmergeMe( void );								// Default constructor
		PmergeMe( PmergeMe const & src );				// Copy constructor: a new instance is created
		PmergeMe &	operator=( PmergeMe const & rhs );	// Copy assignment operator overload
		~PmergeMe( void );								// Destuctor

		//Getters
		std::deque<unsigned int> const &	getDeque( void ) const;
		std::list<unsigned int> const &		getList( void ) const;
		std::vector<unsigned int> const &	getUnsortedSequence( void ) const;
		size_t const &						getLength( void ) const;

		//Add
		void								addSequence( char ** sequence, int size ); 	//parses and adds sequence
		void								addNumber( char * number);					//adds a number to the unsorted sequence

		//Deque
		double								sortDeque( void );
		void								insertElement( unsigned int element);//, unsigned int end );

		//List
		double								sortList( void );

		//Template Functions
		template<typename T>
		bool								isSorted( T const & sequence ) const;
		template<typename T>
		void								printSequence( T const & sequence, size_t const length );

		//Exceptions
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
				return ("Error: Duplicate in sequence!");
			}
		};

	
	private:

		std::vector<unsigned int>	_unsortedSequence;
		std::deque<unsigned int>	_deque;
		std::list<unsigned int>		_list;
		size_t						_length;

		//Deque
		void	_sortPairs( std::deque<unsigned int> & p );
		void	_insertPintoS( std::deque<unsigned int> & p );
		void	_binarySearch( unsigned int value, int pos);
		
		//List
		void												_createSortedPairs( std::list< std::pair<unsigned int, unsigned int> > & pairList );
		std::list< std::pair<unsigned int, unsigned int> >	_mergeSortList(std::list< std::pair<unsigned int, unsigned int> > & Sp );
		std::list< std::pair<unsigned int, unsigned int> >	_merge(std::list< std::pair<unsigned int, unsigned int> > & left, std::list< std::pair<unsigned int, unsigned int> > & right );
		void												_insertPintoSLists( std::list< std::pair<unsigned int, unsigned int> > & Sp );
		void												_insertElement( unsigned int & element);
};


template<typename T>
bool	PmergeMe::isSorted( T const & sequence ) const {
	
	typename T::const_iterator	it1 = sequence.begin();
	typename T::const_iterator it2 = it1;
	it2++;

	while (it2 != sequence.end()) {
		if (*it2 < (*it1))
			return false;
		it1++;
		it2++;
	}
		
	return true;
}

template<typename T>
void	PmergeMe::printSequence( T const & sequence, size_t const length ) {

	typename T::const_iterator	it = sequence.begin();
	
	if (sequence.empty()) {
		std::cout << "Sequence: empty" << std::endl;
		return ;
	}
	if (length > 20) {
		for (int i = 0; i < 10; i++)
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