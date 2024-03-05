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
#include <iomanip> //for setw
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

int	PhoneBook::numberContacts = 0;

void	PhoneBook::addContact(void)
{
	int	index;

	index = this->numberContacts;
	if (index >= 7)
		index -= 7;
	this->contacts[index].setFirstName();
	this->contacts[index].setLastName();
	this->contacts[index].setNickname();
	this->contacts[index].setPhoneNumber();
	this->contacts[index].setDarkestSecret();	

	if (this->numberContacts < 8)
		this->numberContacts += 1;
	std::cout << "New contact successfully added! You now have " 
			<< this->numberContacts << " contact(s)." << std::endl;
	
	return ;
}

void	PhoneBook::searchContact(void)
{
	int	i = 0;
	const int	columnWidth = 10;
	//const int	columnSeparator = ' |';

//set it right aligned!
	while (i < this->numberContacts)
	{
		std::cout << std::setw(10) << "index" << '|' 
				<< std::setw(10) << "First Name" << '|' 
				<< std::setw(10) << "Last Name" << '|' 
				<< std::setw(10) << "Nickname" << '|' << std::endl;
		std::cout << std::setw(columnWidth) << i + 1 << '|'
			<< std::setw(columnWidth) << contacts[i].getFirstName() << ' |'
			<< std::setw(columnWidth) << contacts[i].getLastName() << ' |'
			<< std::setw(columnWidth) << contacts[i].getNickname() << std::endl;
		i++;
	}
	return ;
}

