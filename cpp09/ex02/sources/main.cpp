/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 15:35:31 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/06/18 14:02:40 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"
#include <iostream>

int	main( int argc, char **argv ) {

	if (argc == 1) {
		std::cout << "Nothing to sort. Input a positive integer sequence to be sorted." << std::endl;
		return 0;
	}

	try {

		PmergeMe	sequence1;

		std::cout << sequence1 << std::endl;

		sequence1.addSequence( argv+1, argc-1);
		std::cout << "Input OK!" << std::endl;
		std::cout << "Length of Sequence: " << sequence1.getLength() << std::endl;
		std::cout << sequence1 << std::endl;

		std::cout << "Deque: \t";
		sequence1.printSequence(sequence1.getDeque(), sequence1.getLength());

		std::cout << "List: \t";
		sequence1.printSequence(sequence1.getList(), sequence1.getLength());

		sequence1.sortDeque();
		std::cout << "Deque sorted: \t";
		sequence1.printSequence(sequence1.getDeque(), sequence1.getLength());
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	

	return 0;
}