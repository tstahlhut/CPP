/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 17:08:51 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/14 15:11:23 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _BRAIN_HPP
# define _BRAIN_HPP

# include <iostream>
# include <string>

class	Brain {

	public:
		Brain( void );									// Default constructor 
		Brain( Brain const & src );						// Copy constructor
		Brain &	operator=( Brain const & rhs );			// Copy assignment operator overload
		~Brain( void );									// Destuctor

		std::string	getIdeas(int index ) const;			// Getter
		void	setIdeas( std::string const newIdea ) ;	// Setter

	private:
		std::string	_ideas[100]; // array of 100 ideas
};


#endif