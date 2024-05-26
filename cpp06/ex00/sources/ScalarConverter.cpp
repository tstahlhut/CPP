/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:24:38 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/15 16:10:18 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/ScalarConverter.hpp"

// Default Constructor

ScalarConverter::ScalarConverter( void ) {

	std::cout << "Default Constructor called" << std::endl;

	return ;
}

// Copy Constructor

ScalarConverter::ScalarConverter( ScalarConverter const & src ) {

	std::cout << "Copy Constructor called" << std::endl;

	*this = src ;

	return ;
}

// Copy assignment operator overload

ScalarConverter &	ScalarConverter::operator=( ScalarConverter const & rhs ) {

	std::cout << "Copy assignement operator called" << std::endl;

	if (this == &rhs)
		return *this;

	return *this ;
}

// Destructor

ScalarConverter::~ScalarConverter( void ) {

	std::cout << "Destructor called" << std::endl;

	return ;
}

void	ScalarConverter::convert( std::string literal ) {

	int	dataType = 0;

	char	c = 0;
	int		i = 0;
	double	d = 0;
	float	f = 0;

	int	outOfRange = 0;

	// determine which data type
	if (isChar(literal, &outOfRange)) 
		dataType = 1;
	else if (isInt(literal, &outOfRange))
		dataType = 2;
	else if (isFloat(literal, &outOfRange))
		dataType = 3;
	else if (isDouble(literal, &outOfRange))
		dataType = 4;

	// convert data types
	std::istringstream	input(literal);
	switch (dataType) {
		case 1:
			input >> c;						// is char
			i = static_cast<int>(c);		// convert to int
			d = static_cast<double>(c);		// convert to double
			f = static_cast<float>(c);		// convert to float
			break;

		case 2:
			//std::cout << "is int" << std::endl;
			input >> i;						// is int
			c = static_cast<char>(i);		// convert to char
			d = static_cast<double>(i);		// convert to double
			f = static_cast<float>(i);		// convert to float
			break;

		case 3:
			//std::cout << "is float" << std::endl;
			input >> f;						// is float
			i = static_cast<int>(f);		// convert to int
			c = static_cast<char>(f);		// convert to char
			d = static_cast<double>(f);		// convert to double
			break;

		case 4:
			//std::cout << "is double" << std::endl;
			input >> d;						// is double
			c = static_cast<char>(d);		// convert to char
			i = static_cast<int>(d);		// convert to int
			f = static_cast<float>(d);		// convert to float
			break;

		default:
			if (!specialCase(literal))		// nan, inf, ...
				std::cout << "Conversion impossible" << std::endl;
			return ;
	}

	// print all
	printValues(outOfRange, c, i, f, d);

	return ;
}

/* check data type logic:
	- istringstream reads into the specified data type from the stringstream as long as possible,
	this means until max capacity of data type is reached or in case of int, float and double
	as long as it is numeric
	- Therefore, I return true only if the end of file (eof) is reached
	- isChar: 
		- I have to check if it is an int first, otherwise char returns true for ints;
			iss >> i does however not return true for characters, e.g. 'c'
		- check min and max of char and set flag if it is out of range of size char
		- somehow (iss >> c && iss.eof()) does not work, therefore I took a string and check its length*/

bool	isChar( std::string	literal , int *outOfRange) {

	std::istringstream	iss(literal);
	std::string			c;
	int					i;

	// check if int
	if (iss >> i && iss.eof()) {
		// check if exceeds max or min char size and sets flag
		//std::cout << "SCHAR_MIN: " << SCHAR_MIN << " c: " << i << "UHCAR_MAX: " << UCHAR_MAX << std::endl;
		if (i < SCHAR_MIN || i > UCHAR_MAX)
			*outOfRange = 1;
		return false;
	}

	// clear error flags
	iss.clear();
	// set stream to beginning	
	iss.seekg(0);	
	
	// check if char
	if (iss >> c && c.length() == 1)
		return true;
	else 
		return false;
}


bool	isInt(  std::string	literal, int * outOfRange) {

	std::istringstream	iss(literal);
	int	i;

	// have to check if everything was converted, otherwise it will return true for "0.0f" because it only evaluates "0"
	if (iss >> i && iss.eof()) 
		return true;

	else {
		//std::cout << "INT_MIN: " << INT_MIN << " i: " << i << "INT_MAX: " << INT_MAX << std::endl;
		if (INT_MIN == i || i == INT_MAX) // isstringstream only stores the max that it can store in an int
			*outOfRange = 2;
		return false;
	}
}


// checks with istringstream if it is a float with 'f', e.g. 0.0f

bool	isFloat(  std::string	literal, int* outOfRange ) {

	std::istringstream	iss(literal);
	double		f;
	std::string	lastChar;

	iss >> f;
	if ((-FLT_MAX) > f || f > FLT_MAX) {
		*outOfRange = 3;
		return false;
	}
	if (iss >> lastChar && lastChar == "f" && iss.eof()) 
		return true;

	return false;
}

bool	isDouble(  std::string	literal, int * outOfRange ) {

	std::istringstream	iss(literal);
	double	d;
	double endBits;

	// fits in a double
	if (iss >> d && iss.eof()) {
		//std::cout << "isDouble: " << d << std::endl;
		if (DBL_MIN == d || d == DBL_MAX)
			*outOfRange = 3;
		return true;
	}

	// else: check remaining bits until eof (maybe they are not numeric)
	while (!iss.eof()) {
		if (!(iss >> endBits)) {
			//std::cout << "not numeric" << std::endl;
			return false;
		}
	}

	//std::cout << "DLB_MIN " << DBL_MIN << "| d: " << d << "DBL_MAX: " << DBL_MAX << std::endl;
	if ((-DBL_MAX) == d || d == DBL_MAX)
		*outOfRange = 4;
	return true;
}


bool	specialCase( std::string literal ) {

	std::istringstream	iss(literal);
	std::string			str;

	iss >> str;
	if (iss.eof() && (str == "nan" || str == "nanf")) {
		printValues(2, 0, 0, std::numeric_limits<float>::quiet_NaN(), std::numeric_limits<double>::quiet_NaN());
		return true;
	}
	else if (iss.eof() && (str == "inf" || str == "inff" || str == "+inf" || str == "+inff")) {
		printValues(2, 0, 0, std::numeric_limits<float>::infinity(), std::numeric_limits<double>::infinity());
		return true;
	}
	else if (iss.eof() && (str == "-inf" || str == "-inff")) {
		printValues(2, 0, 0, (-1) * std::numeric_limits<float>::infinity(), (-1) * std::numeric_limits<double>::infinity());
		return true;
	}
	return false;
}

void	printValues(int outOfRange, char c, int i, float f, double d) {

	// print c
			
			if (outOfRange)
				std::cout << "char: impossible" << std::endl;			
			else if (c < 32 || c > 126)
				std::cout << "char: Non displayable" << std::endl;
			else
				std::cout << "char: '" << c << "'" << std::endl;

	//print i

			if (outOfRange > 1)
				std::cout << "int: impossible" << std::endl;
			else
				std::cout << "int: " << i << std::endl;

	//print f

			if (outOfRange > 2)
				std::cout << "float: impossible" << std::endl;
			else if (f == i)
				std::cout << "float: " << f << ".0f" << std::endl;
			else
				std::cout << "float: " << f << "f" << std::endl;
				

	//print d

			if (outOfRange > 3)
				std::cout << "double: impossible" << std::endl;
			else if (d == i)
				std::cout << "double: " << f << ".0" << std::endl;
			else
				std::cout << "double: " << d << std::endl;
			
			return;
}
