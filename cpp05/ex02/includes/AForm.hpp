/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:25:38 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/17 17:54:12 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _AFORM_HPP_
# define _AFORM_HPP_

# include <stdexcept>
# include <iostream>
# include <string>
# include "../includes/Bureaucrat.hpp"

class Bureaucrat;

class AForm {

	public:
		AForm( std::string AFormName, int const gradeToSignAForm, int const gradeToExecuteAForm );
		AForm( AForm const & src );
		AForm&	operator=( AForm const & rhs );
		virtual ~AForm( void );


		// exceptions
		class GradeTooHighException : public std::exception {
			public:
				virtual const char*	what( void ) const throw() {
					return "Grade too high";
				}
			};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char*	what( void ) const throw() {
					return "Grade too low";
				}
			};

	// getters
		std::string	getName( void ) const;
		bool		isSigned( void ) const;
		int 		getGradeToSign( void ) const;
		int			getGradeToExec( void ) const;

		void		beSigned( Bureaucrat const & bureaucrat );

	private:
		AForm( void );
		std::string const	_name;			// Form name
		bool				_signed;		// Form signed?
		int const			_gradeSign;		// Grade required to sign form
		int const			_gradeExec;		// Grade required to execute form
};

std::ostream&	operator<<( std::ostream & o, AForm const & rhs );	
#endif