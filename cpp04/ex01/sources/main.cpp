/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 14:42:59 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/11 18:18:16 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Brain.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"

int	main( void ) {

//	const Animal*	j = new Dog();
//	const Animal*	i = new Cat();

	Cat	basic;
	std::cout << "start of scope" << std::endl << std::endl;
	{
		Cat	tmp = basic;
		std:: cout << "end of scope" << std::endl << std::endl;
	}
	std:: cout << "end of scope" << std::endl;

	//const Animal	array[10];

//	for (int i = 0; i < 5; i++)
//		array[i] = new Dog();

//	delete j;
//	delete i;
	

	
	return 0;
}