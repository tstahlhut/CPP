/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   template.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:16:59 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/11 13:54:51 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// This is a template for a class in Orthodox Canoncial Form

#ifndef _TEMPLATE_HPP
# define _TEMPLATE_HPP

class	Template {

	public:
		Template( void );								// Default constructor (can also be put into private if user should not be able to use it )
		Template( Template const & src );				// Copy constructor: a new instance is created
		Template &	operator=( Template const & rhs );	// Copy assignment operator overload
		~Template( void );								// Destuctor

	
	private:
};


#endif