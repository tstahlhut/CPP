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

	std::istringstream	input(literal); // convert string to stream to be able to convert it further

	int	dataType = 0;

	char	c = 0;
	int		i = 0;
	double	d = 0;
	float	f = 0;

	// determine which data type
	if (isInt(input))
		dataType = 2;
	else if (isChar(input)) 			// test for int first, then char (otherwise char returns true for int)
		dataType = 1;
	else if (isDouble(input))
		dataType = 3;
	else if (isFloat(input))
		dataType = 4;


	// convert data types
	switch (dataType) {
		case 1:
			input >> c;						// is char
			i = static_cast<int>(c);		// convert to int
			d = static_cast<double>(c);		// convert to double
			f = static_cast<float>(c);		// convert to float
			break;

		case 2:
			std::cout << "is int" << std::endl;
			input >> i;						// is int
			c = static_cast<char>(i);		// convert to char
			d = static_cast<double>(i);		// convert to double
			f = static_cast<float>(i);		// convert to float
			break;

		case 3:
			std::cout << "is double" << std::endl;
			input >> d;						// is double
			c = static_cast<char>(d);		// convert to char
			i = static_cast<int>(d);		// convert to int
			f = static_cast<float>(d);		// convert to float
			break;

		case 4:
			std::cout << "is float" << std::endl;
			input >> f;						// is float
			i = static_cast<int>(f);		// convert to int
			c = static_cast<char>(f);		// convert to char
			d = static_cast<double>(f);		// convert to double
			break;

		default:
			std::cout << "Conversion impossible" << std::endl;
			return ;
	}

	// print all
			if (c < 32 || c > 126)
				std::cout << "char: Non displayable" << std::endl;
			else
				std::cout << "char: '" << c << "'" << std::endl;
			if (INT_MIN <= i || i <= INT_MAX) // funktioniert nicht, da bei max_int i = 0
				std::cout << "int: " << i << std::endl;
			else
				std::cout << "int: impossible" << std::endl;
			std::cout << std::fixed << std::setprecision(1) << "float: " << f << "f" << std::endl; // is there a 
			std::cout << "double: " << d << std::endl;
			

	input.clear();
	input.str(std::string());; // empty buffer

}

// somehow (iss >> c && iss.eof()) does not work, therefore I took a string and check its length

bool	isChar( std::istringstream & iss ) {

	std::string		c;

	if (iss >> c && c.length() == 1)
		return true;
	else {
		iss.clear();
		iss.seekg(0);
		return false;
	}
}

bool	isInt( std::istringstream & iss) {

	int	i;
	if (iss >> i && iss.eof()) {// have to check if everything was converted, otherwise it will return true for "0.0f" because it only evaluates "0"
		iss.seekg(0);
		return true;
	}
	else {
		std::cout << i << std::endl;
		iss.clear();
		iss.seekg(0);
		return false;
	}
/*	int	i;
	if (!(iss >> i) || iss.peek() != std::char_traits<int>::eof())
		return false;
	return true;*/
}


bool	isDouble( std::istringstream & iss) {

	double	d;
	if (iss >> d && iss.eof())
		return true;
	else {
		iss.clear();
		iss.seekg(0);
		return false;
	}
}

// checks with istringstream if it is a float with 'f', e.g. 0.0f

bool	isFloat( std::istringstream & iss) {

	float		f;
	std::string	lastChar;

	if (iss >> f && iss >> lastChar && lastChar == "f" && iss.eof()) {
		iss.seekg(0);
		return true;
	}

	else {
		iss.clear();
		iss.seekg(0);
		return false;
	}
}