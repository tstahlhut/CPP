/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 15:35:31 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/06/26 18:32:44 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"
#include <iostream>
#include <iomanip>

int	main( int argc, char **argv ) {

	if (argc == 1) {
		std::cout << "Nothing to sort. Input a positive integer sequence to be sorted." << std::endl;
		return 0;
	}

	try {

		PmergeMe	sequence;


		sequence.addSequence( argv+1, argc-1);

		std::cout << "Before:\t";
		sequence.printSequence(sequence.getUnsortedSequence(), sequence.getLength());

		double timeDeque = sequence.sortDeque();
		double	timeList = sequence.sortList();

		std::cout << "After:\t";
		sequence.printSequence(sequence.getList(), sequence.getLength());

		std::cout << "Time to process a range of " << sequence.getLength() << " elements with std::list:\t";
		std::cout << std::fixed << std::setprecision( 6 );
		std::cout << timeList << " us" << std::endl;

		std::cout << "Time to process a range of " << sequence.getLength() << " elements with std::deque:\t";
		std::cout << timeDeque << " us" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	

	return 0;
}