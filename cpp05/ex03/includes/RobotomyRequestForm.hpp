/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:43:33 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/21 16:08:45 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ROBOTOMYREQUESTFORM_HPP_
# define _ROBOTOMYREQUESTFORM_HPP_

# include "AForm.hpp"

class  RobotomyRequestForm : public AForm {

	public:
		RobotomyRequestForm( std::string target );
		RobotomyRequestForm( RobotomyRequestForm const & src );
		RobotomyRequestForm&	operator=( RobotomyRequestForm const & rhs );
		~RobotomyRequestForm( void );

		void	execute( Bureaucrat const & executor) const;

	private:
		RobotomyRequestForm( void );
		
		std::string const	_target;

};

#endif