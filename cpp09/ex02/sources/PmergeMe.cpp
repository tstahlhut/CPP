/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:24:38 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/11/14 16:06:27 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/PmergeMe.hpp"

/* ************************************************************************** */
/*                Constructors & Destructor                                   */
/* ************************************************************************** */

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
		this->_unsortedSequence = rhs._unsortedSequence;
		this->_length = rhs._length;
	}

	return *this ;
}

// Destructor
PmergeMe::~PmergeMe( void ) {

//	std::cout << "Destructor called" << std::endl;

	return ;
}


/* ************************************************************************** */
/*                Getters                                                     */
/* ************************************************************************** */

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



/* ************************************************************************** */
/*                Member Functions  (General)                                 */
/* ************************************************************************** */

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
	
	return;
}

/* addSequence: checks given sequence (array) and stores it in _unsortedSequence
	1. is a digit
	2. is an unsigned int (positiv and not bigger than UINT_MAX)
	3. no duplicates in sequence
	Only if all three points are true, the sequence is saved,
	otherwise an exeption is thrown*/

void	PmergeMe::addSequence( char ** sequence, int size ) {

	//check for wrong symbols (only positive integer allowed)
	for (int i = 0; i < size; i++) {
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
	
	return ;
}

/* ************************************************************************** */
/*                Member Functions  (Helper Functions)                        */
/* ************************************************************************** */

unsigned int	max( unsigned int a, unsigned int b ) {

	return a >= b ? a : b;
}

unsigned int	min( unsigned int a, unsigned int b ) {

	return a <= b ? a : b;
}

unsigned int	Jacobsthal( unsigned int n1, unsigned int n2) {

	return n1 * 2 + n2;
}

double	calcTime( std::clock_t start ) {

	double duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;

	return duration;
}

/* ************************************************************************** */
/*                Member Functions  (Sort Deque)                              */
/* ************************************************************************** */

/* 1. sortPairs: separate deque into pairs, sort pairs, copy max values of pairs into S and minvalues into p
	S = this->_deque 
	I do this in one step by looping through sequence and storing min values in p and max values in S.
	This safes copying time and memory. But it does not use the insertion sort.*/

void	PmergeMe::_sortPairs( std::deque<unsigned int> & p ) {
	
	for (size_t i = 1; i < (this->_length - (this->_length % 2)) ; i = i + 2){ // if len=4, i should iterate until i=3; if len=5, the same
		this->_deque.push_back(max(this->_unsortedSequence[i-1], this->_unsortedSequence[i]));
		p.push_back(min(this->_unsortedSequence[i-1], this->_unsortedSequence[i]));
	//	i++;
	}
	if (this->_length % 2 == 1)
		p.push_back(this->_unsortedSequence[this->_length - 1]);

	return;
}

/* 2A. insertionSortDeque: modified insertion sort deque S so that deque p stays aligned */

void	insertionSortDeque(std::deque<unsigned int> & S, std::deque<unsigned int> & p) {

	for (unsigned int i = 1; i < S.size(); i++) {
		unsigned int key[2] = {S[i], p[i]};
		int	j = i - 1;
	
		while ( j >= 0 && key[0] < S[j]) {
			S[j + 1] = S[j];
			p[j + 1] = p[j]; // p is sorted so that it stays aligned to S
			--j;
		}
		j += 1;
		S[j] = key[0];
		p[j] = key[1];
	}
}

/* 2B. mergeSortDeque */

void merge(std::deque<unsigned int> & S, std::deque<unsigned int> & p, int const begin, int const mid, int const end) {

    int const Lsize = mid - begin + 1;
    int const Rsize = end - mid;

    std::deque<unsigned int> SL(Lsize);
    std::copy(S.begin() + begin, S.begin() + mid + 1, SL.begin());

    std::deque<unsigned int> SR(Rsize);
    std::copy(S.begin() + mid + 1, S.begin() + end + 1, SR.begin());

    std::deque<unsigned int> pL(Lsize);
    std::copy(p.begin() + begin, p.begin() + mid + 1, pL.begin());

    std::deque<unsigned int> pR(Rsize);
    std::copy(p.begin() + mid + 1, p.begin() + end + 1, pR.begin());

    int Li = 0;
    int Ri = 0;
    int i = begin;

    while (Li < Lsize && Ri < Rsize) {
        if (SL[Li] <= SR[Ri]) {
            S[i] = SL[Li];
            p[i] = pL[Li];
            Li++;
        } else {
            S[i] = SR[Ri];
            p[i] = pR[Ri];
            Ri++;
        }
        i++;
    }

    while (Li < Lsize) {
        S[i] = SL[Li];
        p[i] = pL[Li];
        Li++;
        i++;
    }

    while (Ri < Rsize) {
        S[i] = SR[Ri];
        p[i] = pR[Ri];
        Ri++;
        i++;
    }
	return;
}

void mergeSort(std::deque<unsigned int> & S, std::deque<unsigned int> & p, int const begin, int const end) {
	
    if (begin >= end)
        return;

    int mid = begin + (end - begin) / 2;

    mergeSort(S, p, begin, mid);

    mergeSort(S, p, mid + 1, end);
    merge(S, p, begin, mid, end);
}


void	PmergeMe::insertElement( unsigned int element) {

	for (std::deque<unsigned int>::iterator it = this->_deque.begin(); it < this->_deque.end(); it++) {
		if (element < *it) {
			this->_deque.insert(it, element);
			return ;
		}
	}
	return ;
}

int	PmergeMe::_binarySearch( unsigned int value, unsigned int pos) {
	
	// limit area to search for: from beginning (p element could be the smallest) to 
	std::deque<unsigned int>::iterator left = this->_deque.begin();
	std::deque<unsigned int>::iterator right = this->_deque.end();
	if (pos >= 0 && pos < this->_deque.size())
		right = this->_deque.begin() + pos;		
		
	std::deque<unsigned int>::iterator middle = left + (right - left) / 2;
	
	while (middle != right && middle != left) {
		//std::cout << "binary: value = " << value << " left = " << *left << " right =" << *right << " middle = " << *middle << std::endl;
		if (value < *middle) {
			right = middle;
			// in the case that (right - left) / 2 = 0, middle should be equal to right and not left
			//middle = right - (right - left) / 2;
		}
		else { // as there are no numbers twice value cannot be equal to *middle
			left = middle;
			// in the case that (right - left) / 2 = 0, middle should be equal to left and not right
			
		}
		middle = left + (right - left) / 2;
	}
	// check if value has to be inserted left or right of middle
	if (value > *middle)
		++middle;
	//std::cout << "binary: value = " << value << " left = " << *left << " right =" << *right << " middle = " << *middle << std::endl;
	unsigned int insert_position = std::distance(this->_deque.begin(), middle);
	this->_deque.insert(middle, value);

	if (insert_position > pos)
		return 1;
	return 0;
}


/* 3. insert p into S
	//we re-sort p: partition p into groups (size of groups: Jacobsthal numbers + 1) and sort the elements within these groups in descending order according to their indexes:
	//p0, p1 (stay the same), p3, p4, p6, p5, p
	// I do not rearrange p but just modify the order in which p's elements are inserted into S (this safes copying time and memory) */

void	PmergeMe::_insertPintoS( std::deque<unsigned int> & p ) {

	unsigned int	J1 = 0; // first Jacobsthal number
	unsigned int	J2 = 1; //second jacobsthal number
	unsigned int	J = Jacobsthal(J1, J2);
	unsigned int	end = J1;
	unsigned int	J_case = 0; // binarySearch returns 1, if element was inserted at last possible position which means that search interval for next element is 1 element shorter (if J != i, i.e. going backwards in p sequence) 
	unsigned int	n = 0;	// number of elements inserted
	int				pos; // position until which to search in S
	
	
	// we add one number at the front of p, so that the loop works for the first number where: J = 1 and i (1) > end (0)
	p.push_front(0);
	while ( J < p.size()) {
		for (unsigned int i = J; i > end; i--) {
			// calculate position until which to search in sorted S (we know that we only have to search up to p[i]'s pair which is bigger than p[i])
		//	pos = i - 2 + n - J_case;
		//	if (J == i)
			pos = i - 1 + n;
			// insert p[i] with binary search
			J_case = _binarySearch(p[i], pos);
			n++;
			//insertElement(p[i]);
		}
		end = J;
		J1 = J2;
		J2 = J;
		J = Jacobsthal(J1, J2);
	}
	//insert the last group of elements of p (where J > p.size())
	for (unsigned int i = p.size() - 1; i > end; i--) {
			_binarySearch(p[i], -1);
	}
	return;
}


double	PmergeMe::sortDeque( void ) {

	std::clock_t	startTime = std::clock();
 
	std::deque<unsigned int>	p; //deque of pends (min values)

	//0. Check if already sorted
	if (isSorted(this->_unsortedSequence)) {
		std::cout << "Sequence already sorted!" << std::endl;
		std::copy(this->_unsortedSequence.begin(), this->_unsortedSequence.end(), std::back_inserter(this->_deque));
	}
	else {	
	//1. separate deque into pairs, sort pairs, copy max values of pairs into S and minvalues into p
	_sortPairs(p);	

	//2. sort sequence S (either with insertion sort or with merge sort. In Wikipedia it says "recursively", so I guess merge Sort should be used)
	//insertionSortDeque(this->_deque, p);//insertion sort deque S (modified so that deque p stays aligned)
	mergeSort(this->_deque, p, 0, this->_deque.size() - 1);

	//3. insert p into S
	_insertPintoS(p);
	
	//4.check if really sorted
	if (!isSorted(this->_deque))
			std::cout << "Problem: unsorted!"<< std::endl;
	}

	return calcTime(startTime);
}

/* ************   Sort List  ****************************************************** */


void	PmergeMe::_createSortedPairs( std::list< std::pair<unsigned int, unsigned int> > & pairList ) {

	for (size_t i = 1; i < (this->_length - (this->_length % 2)) ; i = i + 2){ // if len=4, i should iterate until i=3; if len=5, the same
		pairList.push_back(std::make_pair(max(this->_unsortedSequence[i-1], this->_unsortedSequence[i]), min(this->_unsortedSequence[i-1], this->_unsortedSequence[i])));
		//i++;
	}

	return;
}


std::list< std::pair<unsigned int, unsigned int> >	PmergeMe::_merge(std::list< std::pair<unsigned int, unsigned int> > & left, std::list< std::pair<unsigned int, unsigned int> > & right ) {

	std::list< std::pair<unsigned int, unsigned int> >	result;
	std::list< std::pair<unsigned int, unsigned int> >::const_iterator	itl = left.begin();
	std::list< std::pair<unsigned int, unsigned int> >::const_iterator	itr = right.begin();

	//sort and merge left and right list into result in ascending order
	while (itl != left.end() && itr != right.end()) {
		if (itl->first <= itr->first) {
			result.push_back(*itl);
			itl++;
		} else {
			result.push_back(*itr);
			itr++;
		}
	}

	//append remaining elements
	while (itl != left.end()) {
		result.push_back(*itl);
		itl++;
	}
	while (itr != right.end()) {
		result.push_back(*itr);
		itr++;
	}

	return result;
}

std::list< std::pair<unsigned int, unsigned int> >	PmergeMe::_mergeSortList(std::list< std::pair<unsigned int, unsigned int> > & Sp ) {

	if (Sp.size() <= 1)
		return Sp;

	std::list< std::pair< unsigned int, unsigned int> > left(Sp);
	std::list< std::pair<unsigned int, unsigned int> >	right;
	std::list< std::pair<unsigned int, unsigned int> >::iterator	itm = left.begin();
	std::advance(itm, (left.size() / 2));
	right.splice( right.begin(), left, left.begin(), itm);
	
	left = _mergeSortList(left);
	right = _mergeSortList(right);
	
	return _merge(left, right);
}

/*insertElement: Insert 1 element into a sorted list (ascending order)
	-> loop until element is smaller and insert there
	-> or if given element is bigger than last element in list, insert at last position */

void	PmergeMe::_insertElement( unsigned int & element) {

	if (element > this->_list.back())
				this->_list.push_back(element);
	for (std::list<unsigned int>::iterator it = this->_list.begin(); it != this->_list.end(); it++) {
		if (element < *it) {
			this->_list.insert(it, element);
			break;
		}
	}
	return;
}

/* Jacobsthal: The insertion works best if the area searched is one less than a power of two (https://en.wikipedia.org/wiki/Merge-insertion_sort)
	It happens to be that the Jacobsthal numbers are exactly this sequence of numbers. Therefore, we use them in the Ford-Johnson algorithm.
	Jacobsthalnumber: 	0 1 1 3 5 11 21 42 ...
	area searched:		   0 2 2 6 10  22  ...
	*/
void	PmergeMe::_insertPintoSLists( std::list< std::pair<unsigned int, unsigned int> > & Sp ) {

	
	unsigned int	J1 = 0; 				 // first Jacobsthal number
	unsigned int	J2 = 1; 				 // second Jacobsthal number
	unsigned int	J3 = Jacobsthal(J1, J2); // third Jacobsthal number (can be calculated from the two numbers before it)

	std::list< std::pair<unsigned int, unsigned int> >::iterator	it1 = Sp.begin(); //mark beginning of J sublist (p)
	it1--; //move one back so that first element gets copied (because it2 has to be != it1)
	std::list< std::pair<unsigned int, unsigned int> >::iterator	it2 = Sp.begin(); //mark beginning of J sublist (p) / end of J sublist (S)
	it2++; //move one forward so that last element of S gets copied (when comparing to it3)
	std::list< std::pair<unsigned int, unsigned int> >::iterator	it3 = Sp.begin(); //mark beginning of J sublist (S)

	//loop: insert first and second elements according to Jacobsthal number into list
	while (it3 != Sp.end() ) {

		//insert S (which is already sorted) until end of Jacobsthal sublist
		for ( ; it3 != it2; it3++)
			this->_list.push_back(it3->first);

		//insert p from same J group into list (but from the end; they are not sorted and have to find their place in the list)
		if (it2 == Sp.end()) 
			it2--;			//move one backward so that copying begins at last element not the one after
		for ( ; it2 != it1; it2--)
				_insertElement(it2->second);
			
		//reset iterators
		it2 = it3; //it2 is set back to end of J sublist (to its former position)
		it1 = it2; //it1 is advanced to the end of the Jacobsthal numbers group, which will be the beginning in the next loop (it2's former position)
		//compute new Jacobsthal number (and thus range of sublist)
		J1 = J2;
		J2 = J3;
		J3 = Jacobsthal(J1, J2);
		//it2 is advanced to the end of the new Jacobsthal numbers group (but not farther than Sp.end())
		if (std::distance(it2, Sp.end()) > J3 - J2 && it2 != Sp.end())
			std::advance(it2, (J3 - J2)); 
		else 
			it2 = Sp.end();
	}

	//if the length of the original sequence was odd, the last element is missing in Sp and is inserted now
	if (this->_length % 2 == 1)
		_insertElement(this->_unsortedSequence[this->_length - 1]);

	return;

}

//Ford-Johnson Sort Algorithm (Insertion merge) for lists

double	PmergeMe::sortList( void ) {
	
	std::clock_t	startTime = std::clock();
	
	//0. Check if already sorted
	if (isSorted(this->_unsortedSequence)) {
		std::cout << "Sequence already sorted!" << std::endl;
		std::copy(this->_unsortedSequence.begin(), this->_unsortedSequence.end(), std::back_inserter(this->_list));
	}
	else {

	//1. split in pairs (S&p) & sort (S > p) with insertion sort (as its only two, I used max/ min function)
	std::list< std::pair<unsigned int, unsigned int> > Sp;
	_createSortedPairs(Sp);

	//2. sort all values in S in ascending order, recursively with merge sort
	Sp = _mergeSortList(Sp);
	/*std::cout << "After merge: " << std::endl;
	for (std::list< std::pair<unsigned int, unsigned int> >::iterator it = Sp.begin(); it != Sp.end(); it++)
		std::cout << it->first << "\t" << it->second << std::endl;
	*/

	//3. Merge sorted S and unsorted p into 1 list
	_insertPintoSLists(Sp);
	}

	//4. check if sorting was successfull
	if (!isSorted(this->_list))
		std::cout << "Error: List not sorted!" << std::endl;
	else if (this->_list.size() != this->_length)
		std::cout << "Error: Wrong list size!" << std::endl;


	return calcTime(startTime);	
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

/*void	merge(std::deque<unsigned int> & S, std::deque<unsigned int> & p, int const begin, int const mid, int const end ) {

	int const	Lsize = mid - begin + 1;
	int const	Rsize = end - mid;

	//if (Lsize == 0 || Rsize == 0)
	//	return ;

	std::cout << "before merge: " << std::endl << "S: ";
	for (std::deque<unsigned int>::const_iterator it = S.begin(); it != S.end(); it++ )
			std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "begin: " << begin << " mid: " << mid << " end: " << end << std::endl;

	//Copy first subarray: begin to mid
	std::deque<unsigned int> SL(Lsize);
	 std::copy(S.begin() + begin, S.begin() + mid + 1, SL.begin());


	//copy second subarray: mid+1 to end
	std::deque<unsigned int>	SR(Rsize);
	 std::copy(S.begin() + mid + 1, S.begin() + end + 1, SR.begin());

	std::deque<unsigned int>	pL(Lsize);
	std::copy(p.begin() + begin, p.begin() + mid + 1, pL.begin());

	std::deque<unsigned int>	pR(Rsize);
	 std::copy(p.begin() + mid + 1, p.begin() + end + 1, pR.begin());


	int	Li = 0; //index for left array
	int	Ri = 0; //index for right array


	

	std::cout << "SR: ";
	for (std::deque<unsigned int>::const_iterator it = SR.begin(); it != SR.end(); it++ )
			std::cout << *it << " ";
	std::cout << std::endl;
*/	
	//loops through whole array and copies the numbers from the subarrays into it in ascending order (merges the two subarrays)
	/*for (int i = begin; i < end - begin + 1; i++) {
		
		if (Ri == Rsize) {
			S[i] = SL[Li];
			p[i] = pL[Li];
			Li++;
		} else if (Li == Lsize) {
			S[i] = SR[Ri];
			p[i] = pR[Ri];
			Ri++;
		} else if (SR[Ri] > SL[Li]) {
			S[i] = SL[Li];
			p[i] = pL[Li];
			Li++;
		} else {
			S[i] = SR[Ri];
			p[i] = pR[Ri];
			Ri++;
		}
		std::cout << "i: " << i << std::endl;
	}*/
/*
	int i = begin;

	while (Li < Lsize && Ri < Rsize) {
		if (SR[Ri] > SL[Li]) {
			S[i] = SL[Li];
			p[i] = pL[Li];
			Li++;
		} else {
			S[i] = SR[Ri];
			p[i] = pR[Ri];
			Ri++;
		}
		i++;
	}
	while (Li < Lsize) {
		S[i] = SL[Li];
		p[i] = pL[Li];
		Li++;
		i++;
	}
	while (Ri < Rsize) {
			S[i] = SR[Ri];
			p[i] = pR[Ri];
			Ri++;
			i++;
	}
	
std::cout << "after merge: " << std::endl << "S: ";
	for (std::deque<unsigned int>::const_iterator it = S.begin(); it != S.end(); it++ )
			std::cout << *it << " ";
	std::cout << std::endl;

	return ;
}

void	mergeSort(std::deque<unsigned int> & S, std::deque<unsigned int> & p, int const begin, int const end ) {

	if (begin >= end)
		return ;

		
	int	mid = begin + (end - begin) / 2;
	std::cout << " merge sort: " << "begin: " << begin << " mid: " << mid << " end: " << end << std::endl;
	std::cout << "1 merge sort: " << "begin: " << begin << " end: " << mid << std::endl;
	
	mergeSort(S, p, begin, mid);
	std::cout << "2 merge sort: " << "begin: " << mid + 1 << " end: " << end << std::endl;
	
	mergeSort(S, p, mid + 1, end);
	merge(S, p, begin, mid, end);

	return ;
}
void merge(std::deque<unsigned int> & S, std::deque<unsigned int> & p, int const begin, int const mid, int const end) {
    int const Lsize = mid - begin + 1;
    int const Rsize = end - mid;

    // Copy first subarray: begin to mid
    std::deque<unsigned int> SL(Lsize);
    std::copy(S.begin() + begin, S.begin() + mid + 1, SL.begin());

    // Copy second subarray: mid + 1 to end
    std::deque<unsigned int> SR(Rsize);
    std::copy(S.begin() + mid + 1, S.begin() + end + 1, SR.begin());

    // Copy corresponding p subarrays
    std::deque<unsigned int> pL(Lsize);
    std::copy(p.begin() + begin, p.begin() + mid + 1, pL.begin());

    std::deque<unsigned int> pR(Rsize);
    std::copy(p.begin() + mid + 1, p.begin() + end + 1, pR.begin());

    int Li = 0; // Index for left array
    int Ri = 0; // Index for right array
    int i = begin;

    // Merge the two subarrays back into S and p
    while (Li < Lsize && Ri < Rsize) {
        if (SL[Li] <= SR[Ri]) {
            S[i] = SL[Li];
            p[i] = pL[Li];
            Li++;
        } else {
            S[i] = SR[Ri];
            p[i] = pR[Ri];
            Ri++;
        }
        i++;
    }

    // Copy any remaining elements of SL
    while (Li < Lsize) {
        S[i] = SL[Li];
        p[i] = pL[Li];
        Li++;
        i++;
    }

    // Copy any remaining elements of SR
    while (Ri < Rsize) {
        S[i] = SR[Ri];
        p[i] = pR[Ri];
        Ri++;
        i++;
    }

    // Debug output
    std::cout << "after merge: " << std::endl << "S: ";
    for (std::deque<unsigned int>::const_iterator it = S.begin(); it != S.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}*/