/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:07:44 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/02/27 13:10:31 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//In this source file the Contact class is defined.

#include <iostream>
#include "Contact.class.hpp"

// Definition of the constructor
Contact::Contact(void)
{
	/*std::cout << "First name: " << this->_first_name << std::endl;
	std::cout << "Last name: " << this->_last_name << std::endl;
	std::cout << "Nickame: " << this->_nickname << std::endl;
	std::cout << "Phone Number: " << this->_phone_number << std::endl;
	std::cout << "Darkest secret: " << this->_darkest_secret << std::endl;*/
	return;
}

//Definition of destructor
Contact::~Contact(void)
{
	std::cout << "destructor called" << std::endl;
	return;
}

void	Contact::set_first_name(char *str)
{
	if (str.length() > 0)
		this->_first_name = str;
	std::cout << "First name: " << this->_first_name << std::endl;
	return;
}