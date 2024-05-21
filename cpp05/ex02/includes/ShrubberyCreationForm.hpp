/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:43:33 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/21 15:34:46 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _SHRUBBERYCREATIONFORM_HPP_
# define _SHRUBBERYCREATIONFORM_HPP_

# include "AForm.hpp"
# include <fstream>

class  ShrubberyCreationForm : public AForm {

	public:
		ShrubberyCreationForm( std::string const target );
		ShrubberyCreationForm( ShrubberyCreationForm const & src );
		ShrubberyCreationForm&	operator=( ShrubberyCreationForm const & rhs );
		~ShrubberyCreationForm( void );

		void	execute( Bureaucrat const & executor) const;

	private:
		ShrubberyCreationForm( void );
		
		std::string const	_target;

};

#endif