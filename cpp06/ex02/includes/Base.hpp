/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:04:26 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/26 18:01:08 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _BASE_HPP_
# define _BASE_HPP_

# include <iostream>
# include <cstdlib>

class	Base {

	public:	
		virtual ~Base( void );

	
	
};

Base *	generate(void);
void 	identify(Base* p);
void 	identify(Base& p);

#endif