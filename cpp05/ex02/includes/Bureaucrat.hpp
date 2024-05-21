/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 08:39:04 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/21 15:33:45 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _BUREAUCRAT_HPP_
# define _BUREAUCRAT_HPP_

# include  <string>
# include <iostream>
# include <stdexcept>
# include "../includes/AForm.hpp"

class AForm;

class Bureaucrat
{
	public:
		Bureaucrat( std::string name, int grade );
		Bureaucrat( Bureaucrat const & src );
		Bureaucrat&	operator=( Bureaucrat const & rhs );
		~Bureaucrat();

		// Custom exceptions for bureaucrat class
		class GradeTooHighException : public std::exception {
				public:
					virtual const char*	what( void ) const throw() {
						return "Grade too high";
					}
		};

		class	GradeTooLowException : public std::exception {
				public:
					virtual const char*	what( void ) const throw() {
						return "Grade too low";
					}
		};

	// getters
		std::string	getName( void ) const;
		int			getGrade( void ) const;

	// other member functions
		void		incrementGrade( void );
		void		decrementGrade( void );
		void		signForm( AForm & form ) const;
		void		executeForm( AForm const & form );

	private:
		Bureaucrat( void );
		std::string const	_name; // should it be const? (subject: "a constant name")
		int			_grade;		// 1 to 150
};

std::ostream &	operator<<( std::ostream & o, Bureaucrat const & rhs);


#endif