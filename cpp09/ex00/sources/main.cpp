/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 15:35:31 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/08/26 15:00:50 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"
#include <iostream>

# define DATA_FILE	"./data/data.csv"
# define DELIMITER	","

int	main( int argc, char **argv ) {

	if (argc != 2) {
		std::cout << "Error: 1 database file required" << std::endl;
		return 0;
	}


	try {

		//start btc (init database)
		BitcoinExchange btc(DATA_FILE, DELIMITER);

		//open input file
		std::ifstream	inputFile(argv[1]);
		if (inputFile.fail()) {
			std::cout << "Error: Input file failed to open" << std::endl;
			return 1;
		}
		
		//iterate through inputFile and get bitcoin results
		std::string	line;
		std::getline(inputFile, line); //header: not stored
		while(!inputFile.eof()) {
		
			std::getline(inputFile, line);
			try {
				btc.printBitcoinAmount(line, " | ");
			//	std::cout << line.substr(0, 9) << " => " << 
			}
			catch (std::exception &e) {
				std::cout << e.what()  << " => " << line << std::endl;
				//inputFile.close();
			}
			line.erase();
		}
		inputFile.close();
	}

	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	

	return 0;
}