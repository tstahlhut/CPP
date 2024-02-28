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
	
	void	set_first_name(char *str);
	/*void	set_last_name(string str);
	void	set_nickname(string str);
	void	set_phone_number(string str);
	void	set_darkest_secret(string str);*/

private:
	std::string	_first_name;
	std::string	_last_name;
	std::string	_nickname;
	std::string	_phone_number;
	std::string	_darkest_secret;

};

#endif