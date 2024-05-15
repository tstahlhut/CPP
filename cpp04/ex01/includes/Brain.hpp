/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 17:08:51 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/15 12:12:16 by tstahlhu         ###   ########.fr       */
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

		std::string	getIdeas(int index ) const;				// Getter
		void		setIdeas( std::string const newIdea );	// Setter

	private:
		static int const	_nbIdeas = 100;					// size of array
		std::string			_ideas[_nbIdeas]; 				// array of ideas
};


#endif