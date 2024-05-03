/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:00:00 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/03 10:15:35 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//In this header file the class PhoneBook is declared.

#ifndef PhoneBook_CLASS_H
# define PhoneBook_CLASS_H

# include <iostream>
# include <iomanip> //for setw
# include "Contact.class.hpp"

class	PhoneBook
{

public:
	PhoneBook(void);
	~PhoneBook(void);

	void	addContact(void);
	void	searchContact(void);
	void	printContactList(void);
	void	printContactInfo(std::string str);
	void	displayContact(int index);

private:
	int	_numberContacts;
	int	_index;

	Contact	_contacts[8];
	
};

#endif