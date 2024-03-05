/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:59:56 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/02/27 13:10:56 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// In this header file the class Contact is declared.

#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

class	Contact 
{
	
public:
	Contact(void);		//Constructor
	~Contact( void );		//Destructor
	
	void	setFirstName(void);
	void	setLastName(void);
	void	setNickname(void);
	void	setPhoneNumber(void);
	void	setDarkestSecret(void);

	std::string	getFirstName() const;
	std::string getLastName() const;
	std::string	getNickname() const;
	std::string	getPhoneNumber() const;
	std::string	getDarkestSecret() const;

private:
	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickname;
	std::string	_phoneNumber;
	std::string	_darkestSecret;

};

#endif