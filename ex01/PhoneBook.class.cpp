/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:05:20 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/02/27 13:18:32 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// In this source file the PhoneBook class is defined.

#include <iostream>
#include "PhoneBook.class.hpp"

PhoneBook::PhoneBook(void)
{
	std::cout << "construtor called" << std::endl;
	return;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "destructor called" << std::endl;
	return;
}

int	PhoneBook::number_contacts = 0;

void	PhoneBook::add_contact(void)
{
	std::string	firstname;
	/*std::string	lastname;
	std::string	nickname;
	std::string	phonenumber;
	std::string secret;
*/
	std::cout << "Enter First Name: " << std::endl;
	std::cin >> firstname;
	/*std::cout << "Enter Last Name: " << std::endl;
	std::cin >> lastname;
	std::cout << "Enter Nickname: " << std::endl;
	std::cin >> nickname;
	std::cout << "Enter Phone Number: " << std::endl;
	std::cin >> phonenumber;
	std::cout << "Enter the their darkest secret: " << std::endl;
	std::cin >> secret;*/

	Contact[0]::set_first_name(firstname);

	this->number_contacts += 1;
	std::cout << "New contact successfully added! You now have " 
			<< this->number_contacts << " contact(s)." << std::endl;
	
	return ;
	//Contact	contact1;
	//Contact::Contact(firstname, lastname, nickname, phonenumber, secret);
}