/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:00:00 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/02/27 12:56:31 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//In this header file the class PhoneBook is declared.

#include "Contact.class.hpp"

#ifndef PhoneBook_CLASS_H
# define PhoneBook_CLASS_H

class	PhoneBook
{

public:
	PhoneBook(void);
	~PhoneBook(void);

	Contact	contacts[8];

	void	addContact(void);
	void	searchContact(void);

private:
	static int	numberContacts;
	
};

#endif