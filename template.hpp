/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   template.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:16:59 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/06 19:24:21 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// This is a template for a class in Orthodox Canoncial Form

#ifndef _TEMPLATE_HPP
# define _TEMPLATE_HPP

class	Template {

	public:
		Template( void ); // Default constructor (can also be put into private if user should not be able to use it )
		Template( Template const & src ); // Copy constructor: a new instance is created
		~Template( void );	// Destuctor

		// Copy assignment operator overload
		Template &	operator=( Template const & rhs ); // current instance is updated with rhs instance
	
	private:
}


#endif