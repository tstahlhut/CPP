/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:59:56 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/02 11:08:17 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// In this header file the class Contact is declared.

#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

# include <iostream>
# include <iomanip>
# include <limits>
# include <ios>

class	Contact 
{
	
public:
	Contact(void);		//Constructor
	~Contact(void);	//Destructor
	
	void	setFirstName(void);
	void	setLastName(void);
	void	setNickname(void);
	void	setPhoneNumber(void);
	void	setDarkestSecret(void);

	std::string	getFirstName(void) const;
	std::string getLastName(void) const;
	std::string	getNickname(void) const;
	std::string	getPhoneNumber(void) const;
	std::string	getDarkestSecret(void) const;

private:
	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickname;
	std::string	_phoneNumber;
	std::string	_darkestSecret;

};

#endif