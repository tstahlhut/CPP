/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:24:38 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/06/20 12:52:15 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/PmergeMe.hpp"

// Default Constructor

PmergeMe::PmergeMe( void ) : _deque(), _list(), _length(0){

	//std::cout << "Default Constructor called" << std::endl;

	return ;
}


// Copy Constructor

PmergeMe::PmergeMe( PmergeMe const & src )  {

	//std::cout << "Copy Constructor called" << std::endl;

	*this = src ;

	return ;
}

// Copy assignment operator overload

PmergeMe &	PmergeMe::operator=( PmergeMe const & rhs ) {

//	std::cout << "Copy assignement operator called" << std::endl;

	if (this != &rhs) {

		this->_deque = rhs._deque;
		this->_list = rhs._list;
	}

	return *this ;
}

// Destructor

PmergeMe::~PmergeMe( void ) {

//	std::cout << "Destructor called" << std::endl;

	return ;
}


// Getters

std::deque<unsigned int> const &	PmergeMe::getDeque( void ) const {

	return this->_deque;
}

std::list<unsigned int> const &	PmergeMe::getList( void ) const {

	return this->_list;
}

std::vector<unsigned int> const &	PmergeMe::getUnsortedSequence( void ) const {

	return this->_unsortedSequence;
}

size_t const &	PmergeMe::getLength( void ) const {

	return this->_length;
}



// Member functions

/* addNumber: adds a number to the sequence to be sorted (_unsortedSequence)
		takes a char* string as parameter and converts it to unsigned int
		checks if given number is out of range*/

void	PmergeMe::addNumber( char*	number) {

//convert from char* to int
	long int n = std::strtol (number, 0, 10);

//check if out of range (can be unsigned int)
	if (n == LONG_MIN || n == LONG_MAX || n > UINT_MAX )
		throw std::out_of_range("Error: Value out of range");
	if (n == 0 && number[0] != '0')
		throw std::out_of_range("Error: Value out of range");

//add converted number to sequence 
	this->_unsortedSequence.push_back(static_cast<unsigned int>(n));
	
}

void	PmergeMe::addSequence( char ** sequence, int end ) {

//check for wrong symbols (only positive integer allowed)
	for (int i = 0; i < end; i++) {
		for (int j = 0; sequence[i][j] != '\0'; j++) {
			if (!isdigit(sequence[i][j])) {
				throw WrongSymbolException();
			}
		}
		addNumber(sequence[i]);
		this->_length += 1;
	}

//check for duplicates
	std::vector<unsigned int>	test = this->_unsortedSequence;
	std::sort (test.begin(), test.end());
	std::vector<unsigned int>::iterator	it = std::adjacent_find (test.begin(), test.end());
	if(it != test.end())
		throw DuplicateException();

//copy sequence into deque and list containers (to be sorted)
	//std::copy(this->_unsortedSequence.begin(), this->_unsortedSequence.end(), std::back_inserter(this->_deque));
	std::copy(this->_unsortedSequence.begin(), this->_unsortedSequence.end(), std::back_inserter(this->_list));
	
	return ;
}

unsigned int	max( unsigned int a, unsigned int b ) {

	return a >= b ? a : b;
}

unsigned int	min( unsigned int a, unsigned int b ) {

	return a <= b ? a : b;
}

//original code from https://www.geeksforgeeks.org/jacobsthal-and-jacobsthal-lucas-numbers/
/*
unsigned int	Jacobsthal( unsigned int n ) {

	if (n == 0)
		return 0;
	if (n == 1)
		return 1;

	return Jacobsthal(n - 1) + 2 * Jacobsthal(n - 2);
}
*/

unsigned int	Jacobsthal( unsigned int n1, unsigned int n2) {

	return n1 * 2 + n2;
}

//insertion sort
/*void	insertionSort( unsigned int start, unsigned int	length, std::deque<unsigned int> & deque ) {
	for (unsigned int	i = start; i < length; i++) {
		unsigned int	key = deque[i];
		unsigned int	j = i - 1;
	
		while ( j >= start && key < deque[j]) {
			deque[j + 1] = deque[j];
			--j;
		}
		j += 1;
		deque[j] = key;
	}
	return ;
}
*/

void	PmergeMe::insertElement( unsigned int element) {//, unsigned int end ) {

	for (std::deque<unsigned int>::iterator it = this->_deque.begin(); it < this->_deque.end(); it++) {// (this->_deque.begin() + end); it++) {
		if (element < *it) {
			this->_deque.insert(it, element);
			return ;
		}
	}
	std::cout << "problem in insert function" << std::endl;
	return ;
}

//insertion sort deque S (deque p stays aligned)
/*void	insertionSort()
	for (unsigned int i = 1; i < this->_deque.size(); i++) {
		unsigned int key[2] = {this->_deque[i], p[i]};
		int	j = i - 1;
	
		while ( j >= 0 && key[0] < this->_deque[j]) {
			this->_deque[j + 1] = this->_deque[j];
			p[j + 1] = p[j];
			--j;
		}
		j += 1;
		this->_deque[j] = key[0];
		p[j] = key[1];
	}
*/
std::deque<unsigned int> const &	PmergeMe::sortDeque( void ) {

 //1. sort pairs and separate into S(max value of each pair) and p(min value of each pair) arrays
	std::deque<unsigned int>	p;
	
	for (size_t i = 1; i < (this->_length - (this->_length % 2)) ; i++){ // if len=4, i should iterate until i=3; if len=5, the same
		this->_deque.push_back(max(this->_unsortedSequence[i-1], this->_unsortedSequence[i]));
		p.push_back(min(this->_unsortedSequence[i-1], this->_unsortedSequence[i]));
		i++;
	}
	if (this->_length % 2 == 1)
		p.push_back(this->_unsortedSequence[this->_length - 1]);

//insertion sort deque S (deque p stays aligned)
	for (unsigned int i = 1; i < this->_deque.size(); i++) {
		unsigned int key[2] = {this->_deque[i], p[i]};
		int	j = i - 1;
	
		while ( j >= 0 && key[0] < this->_deque[j]) {
			this->_deque[j + 1] = this->_deque[j];
			p[j + 1] = p[j];
			--j;
		}
		j += 1;
		this->_deque[j] = key[0];
		p[j] = key[1];
	}

//merge
	std::cout << "Merge: " << std::endl;
	// we push p[0] because we know that it is smaller than S[0]
//	this->_deque.push_front(p[0]);
	//we add one number at the front of p, so that the indexes of S and p are aligned again
//	p.push_front(0);

	//we re-sort p: partition p into groups (size of groups: Jacobsthal numbers + 1) and sort the elements within these groups in descending order according to their indexes:
	//p0, p1 (stay the same), p3, p4, p6, p5, p

	unsigned int	J1 = 0; // first Jacobsthal number
	unsigned int	J2 = 1; //second jacobsthal number
	//we add one number at the front of p, so that the indexes of S and p are aligned again when the first element of p is pushed to S
	p.push_front(0);
	unsigned int	J = Jacobsthal(J1, J2);
	unsigned int	inserted = 0;
	unsigned int	end = J1;

	while ( J < p.size()) {
		for (unsigned int i = J; i > end; i--) {
			//std::cout << "i: " << i << " for J: " << J  << " J1: " << J1 << std::endl;
			insertElement(p[i]);//, i + inserted);
			inserted++;
		}
		end = J;
		J1 = J2;
		J2 = J;
		J = Jacobsthal(J1, J2);
	}
	for (unsigned int i = p.size() - 1; i > end; i--) {
			std::cout << "here i: " << i << " for J: " << J  << " J1: " << J1 << std::endl;
			insertElement(p[i]);
	}
	//if (J > p.size())
	//	insertElement(p[J - 1]);//, J - 1 + inserted);
//	std::cout << "J: " << J << " p.size(): " << p.size() << std::endl;
	//this->_deque.push_front(p[J]); // we push p[1] because we know that it is smaller than S[0]
		

	std::cout << "S: ";
	printSequence(this->_deque, this->_length);
	std::cout << "p: ";


	//we partition p into groups with contiguous indexes and sort all elements in that subgroup in ascending order
//	unsigned int	start = 2; // p's first two elements are already inserted, therefore we start at 2
//	unsigned int	i = 2;
	//insertionSort(start, (start + i), p); no need to sort, we just sort according to the INDEX!
//	std::cout << "p: ";
//	printSequence(p, this->_length);
//	for (size_t i = 2; i < p.size(); i++)
//		insertElement(p.size(), p[i]);
//	for (unsigned int i1 = 2; i1 < p.size(); i1++) {

		//std::cout << "i: " << i << "\t Jacobsthal: " << Jacobsthal() << std::endl;
//	}

	for (std::deque<unsigned int>::iterator it = this->_deque.begin() + 1; it != this->_deque.end(); it++)
		if (it < (it - 1))
			std::cout << "unsorted!"<< std::endl;
	std::cout << "Deque sorted!" << std::endl;

	return this->_deque;
}


std::ostream &	operator<<( std::ostream & o, PmergeMe const & rhs ) {


/*//does not work:
	size_t const	len = rhs.getLength();
	std::vector<unsigned int> const	unsortedSeq = rhs.getUnsortedSequence();
	rhs.printSequence(unsortedSeq, len);
	*/
	std::vector<unsigned int>	sequence = rhs.getUnsortedSequence();
	std::vector<unsigned int>::iterator	it = sequence.begin();
	
	if (sequence.empty()) {
		o << "Sequence: empty";
		return o;
	}
	o << "Unsorted sequence: ";
	if (rhs.getLength() > 7) {
		for (int i = 0; i < 7; i++)
			o << *(it + i) << " ";
		o << "[...]";
	}
	else {
		for (std::vector<unsigned int>::iterator it = sequence.begin(); it != sequence.end(); it++ )
			o << *it << " ";
	}
	return o;
}

	//insertion sort
/*	for (unsigned int i = 1; i < this->_length; i++) {
		unsigned int key = this->_deque[i];
		int	j = i - 1;
	
		while ( j >= 0 && key < this->_deque[j]) {
			this->_deque[j + 1] = this->_deque[j];
			--j;
		}
		j += 1;
		this->_deque[j] = key;
	}
*/