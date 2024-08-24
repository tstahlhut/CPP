/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:24:38 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/15 16:10:18 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/BitcoinExchange.hpp"

// Default Constructor

BitcoinExchange::BitcoinExchange( void ) : _database() {

	//std::cout << "Default Constructor called" << std::endl;

	return ;
}


BitcoinExchange::BitcoinExchange( std::string Datafile, std::string Delimiter ) : _delimiter(Delimiter) {

//check file extension
	if (Datafile.compare((Datafile.size() - 4), 5, ".csv") != 0)
		throw WrongFormatException();

//save Database in this->_database
	try {
	this->saveDatabase(Datafile);
	}
	catch (std::exception &e) {
		this->_delimiter.clear();
		this->_file.clear();
		this->_database.clear();
		std::cout << e.what() << std::endl;
		std::cout << "Database could not be intialized." << std::endl;
	}
}


// Copy Constructor

BitcoinExchange::BitcoinExchange( BitcoinExchange const & src )  {

	//std::cout << "Copy Constructor called" << std::endl;

	*this = src ;

	return ;
}

// Copy assignment operator overload

BitcoinExchange &	BitcoinExchange::operator=( BitcoinExchange const & rhs ) {

//	std::cout << "Copy assignement operator called" << std::endl;

	if (this != &rhs) {

		this->_database = rhs._database;
		this->_file = rhs._file;
		this->_delimiter = rhs._delimiter;

	}

	return *this ;
}

// Destructor

BitcoinExchange::~BitcoinExchange( void ) {

//	std::cout << "Destructor called" << std::endl;

	return ;
}


// Member Functions

std::map<std::string, double>	BitcoinExchange::getDatabase( void ) const {

	return this->_database;
}

bool	BitcoinExchange::checkDateFormat( std::string date ) {

//expected date format: yyyy-mm-dd

//check length
	if (date.length() != 10)
		return false;

//check year
	size_t	pos = date.find("-");
	if (pos != 4)
		return false;
	int	year = std::atoi(date.substr(0, pos).c_str());
	if (year < 1900 || year > 9999)
		return false;
	
//check month
	pos = date.rfind("-");
	if (pos != 7)
		return false;
	int	month = std::atoi(date.substr(5, pos).c_str());
	if (month < 1 || month > 12)
		return false;
	pos++;

//check day
	int	day = std::atoi(date.substr(pos, 10).c_str());
	if (day < 1 || day > 31)
		return false;

	return true;

}

void	BitcoinExchange::saveDatabase( std::string Datafile ) {

	if (!this->_database.empty())
		this->_database.clear();

//open file
	std::ifstream	fin(Datafile.c_str());
	if (fin.fail()) {
		std::cout << Datafile << " could not be opened" << std::endl;
		throw FileErrorException();
	}
	//std::cout << "data file opened" << std::endl;

//read into map structure
	std::string	line;
	size_t		pos = 0;
	std::getline(fin, line); //header: not stored
	while(!fin.eof()) {
		
		std::getline(fin, line);
		if (!line.empty()) {
			pos = line.find(this->_delimiter);
			if (!checkDateFormat(line.substr(0, pos))) {
				fin.close();
				throw WrongFormatException();
			}
			this->_database[line.substr(0, pos)] = std::atof(line.substr(pos+1, line.find('\n')).c_str());
			line.erase();
		}
	}
	this->_file = Datafile;
	fin.close();
	//std::cout << *this << std::endl;
}

bool	isNumeric(std::string value) {
	
	int	point = 0;
	for (std::string::const_iterator it = value.begin(); it != value.end(); it++) {
		if (*it == '.')
			point++;
		if (!std::isdigit(*it) && point > 1)
			return false;
	} return true;
}

void	BitcoinExchange::printBitcoinAmount( std::string date_value, std::string delimiter ) {

	size_t	pos = date_value.find(delimiter);
	std::string	date = date_value.substr(0, pos);
	
	if (!checkDateFormat(date)) {
	//	std::cout << date << "\t" << std::isspace(date.c_str()[0]) << "\t" << date.size() << std::endl;
		if (!std::isspace(date.c_str()[0]) && date.size() > 1) //do not print error if line is empty or consits of whitespace only
			std::cout << "Error: Invalid date format: " << date << std::endl;
		return ;
	}

	std::string	output = date;
	output.append(" => ");
	pos += delimiter.length();

	double	value = std::atof(date_value.substr(pos, date_value.length()).c_str());
	
	output.append(date_value.substr(pos, date_value.length()));
	output.append(" = ");

	double	result = getBitcoinAmount(value, date);
	if (result < 0)
		return ;
	
	if (!isNumeric(date_value.substr(pos, date_value.length()))) {
		std::cout << "Error: Value is non-numeric" << std::endl;
		return ;
	}
	
	std::cout << output << result << std::endl;

	return ;
	

}

double	BitcoinExchange::getBitcoinAmount( double value, std::string date) {

	if (value < 0) {
		std::cout << "Error: not a positive number" << std::endl;
		return -1;
	}
	if (value > 1000) {
		std::cout << "Error: too large a number" << std::endl;
		return -1;
	}

	double	result = value * findExchangeRate(date);

	return result;

}

double	BitcoinExchange::findExchangeRate( std::string date ) {

	if (this->_database.count(date)) //returns 1 if found, 0 if not
		return this->_database.find(date)->second;

	std::map<std::string, double>::iterator	lowerBound = this->_database.lower_bound(date);
	//	std::cout << this->_database.upper_bound(date)->first << " " << this->_database.upper_bound(date)->second << std::endl;
	lowerBound--;
	return lowerBound->second;
	
}

std::ostream &	operator<<( std::ostream & o, BitcoinExchange const & rhs ) {

	std::map<std::string, double>	db = rhs.getDatabase();
	if (db.empty()) {
		o << "empty";
		return o;
	}
	for (std::map<std::string, double>::iterator it = db.begin(); it != db.end(); it++)
		o << it->first << " " << it->second << std::endl;

	return o;
}