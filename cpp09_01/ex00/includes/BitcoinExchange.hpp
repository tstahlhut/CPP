/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:16:59 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/06/12 15:18:22 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _BitcoinExchange_HPP
# define _BitcoinExchange_HPP

# include <iostream>
# include <map>
# include <cctype>
# include <stdexcept>
# include <string>
# include <fstream>
# include <cstdlib> //for atof

class	BitcoinExchange {

	public:
		BitcoinExchange( void );
		BitcoinExchange( std::string Datafile, std::string Delimiter );
		BitcoinExchange( BitcoinExchange const & src );	
		BitcoinExchange &	operator=( BitcoinExchange const & rhs );
		~BitcoinExchange( void );


		std::map<std::string, double>	getDatabase( void ) const;

		bool	checkDateFormat( std::string date ) ;
	//	bool	checkValue( unsigned int value ) const;
	//	bool	checkValue( double value ) const;

		void	saveDatabase( std::string Datafile ) ;

		double	findExchangeRate( std::string date ) ;

		double	getBitcoinAmount( double value, std::string date) ;

		void	printBitcoinAmount( std::string date_value, std::string delimiter );

		class WrongFormatException : public std::exception {
			public:
			virtual const char*	what( void ) const throw()
			{
				return ("Error: Wrong format");
			}
		};

		class FileErrorException : public std::exception {
			public:
			virtual const char*	what( void ) const throw()
			{
				return ("Error: File");
			}
		};

	
	private:
		std::map< std::string, double >	_database;

		std::string						_file;
		std::string						_delimiter;
	
};

std::ostream &	operator<<( std::ostream & o, BitcoinExchange const & rhs );


#endif