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
		std::cout << e.what() << std::endl;
		throw InitErrorException();
	}
	if (this->_database.empty())
		throw InitErrorException();
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


/* To determine if a year is a leap year, we apply a simple rule: 
if the year is divisible by 4, it's a leap year, 
except for end-of-century years, which must also be divisible by 400.*/
bool	isLeapYear( int year ) {

	return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0); 
}


/* checks if the format of the date is correct (for data file and input file)*/
bool	BitcoinExchange::checkDateFormat( std::string date ) {

	deleteWhitespaceAtBeginning(date);

//expected date format: yyyy-mm-dd

//check length
	if (date.length() != 10)
		return false;

//check year
	size_t	pos = date.find("-");
	if (pos != 4)
		return false;
	int	year = std::atoi(date.substr(0, pos).c_str());
	if (year < 2009 || year > 3000) //bitcoin started in 2009
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
	// months with 30 days
	if (month == 4 || month == 6 || month == 9 || month == 11)
		return (day <= 30);
	// check day for February
	if (month == 2) {
		if (isLeapYear(year))
			return (day <= 29);
		else
			return (day <= 28);
	}
	return true;

}

bool	BitcoinExchange::isNumeric(std::string value) const {
	
	int	point = 0;
	std::string::const_iterator it = value.begin();
	if (*it == '-')
		it++;
	for (; it != value.end(); it++) {
		if (*it == '.')
			point++;
		if (!std::isdigit(*it) && (*it != '.' || (*it == '.' && point > 1)) && !std::isspace(*it))
			return false;
	} return true;
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
			//check if rest of line is numeric (whitespace after number allowed)
			if (!isNumeric(line.substr(pos+1, line.find('\n'))))
				throw WrongFormatException();
			this->_database[line.substr(0, pos)] = std::atof(line.substr(pos+1, line.find('\n')).c_str());
			line.erase();
		}
	}
	this->_file = Datafile;
	fin.close();
}

void	BitcoinExchange::printBitcoinAmount( std::string date_value, std::string delimiter ) {

	deleteWhitespaceAtBeginning(date_value);
	if (date_value.empty())
		return;

	//find delimiter
	size_t	pos = date_value.find(delimiter);
	if (pos == std::string::npos)
		throw WrongFormatException();
		

	//extract date
	std::string	date = date_value.substr(0, pos);
	if (!checkDateFormat(date)) {
		std::cout << "Error: Invalid date format: " << date << std::endl;
		return ;
	}
	std::string	output = date;
	output.append(" => ");
	pos += delimiter.length();

	//check if rest of string is numeric (whitespace after number allowed)
	if (!isNumeric(date_value.substr(pos, date_value.length())))
		throw WrongFormatException();

	//extract value
	double	value = std::atof(date_value.substr(pos, date_value.length()).c_str());
	
	//calculate result
	double	result = getBitcoinAmount(value, date);
	if (result < 0) //if result negative, number is out of range
		return ;
	
	//print result
	output.append(date_value.substr(pos, date_value.length()));
	output.append(" = ");

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

	if (this->_database.count(date)) { //returns 1 if found, 0 if not
		return this->_database.find(date)->second;
	}
	
	//if date not found in database, the date before is used
	std::map<std::string, double>::iterator	lowerBound = this->_database.lower_bound(date);
	if (lowerBound != _database.begin())
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

void	BitcoinExchange::deleteWhitespaceAtBeginning( std::string & str) {

	//delete whitespace at the beginning
	std::string::iterator	it = str.begin();
	while (std::isspace(*it)) {
		str.erase(it);
	}
}