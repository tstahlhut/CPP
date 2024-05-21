/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern copy.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 08:39:04 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/21 17:13:38 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _INTERN_HPP_
# define _INTERN_HPP_

# include  <string>
# include <iostream>
# include "../includes/AForm.hpp"
# include "../includes/ShrubberyCreationForm.hpp"
# include "../includes/RobotomyRequestForm.hpp"
# include "../includes/PresidentialPardonForm.hpp"

class AForm;

class Intern
{
	public:
		Intern( void );
		Intern( Intern const & src );
		Intern&	operator=( Intern const & rhs );
		~Intern();

		AForm*	makeForm( std::string form, std::string target );

};

#endif