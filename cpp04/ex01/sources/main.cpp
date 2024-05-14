/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 14:42:59 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/14 15:15:33 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Brain.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"

int	main( void ) {

//	const Animal*	j = new Dog();
//	const Animal*	i = new Cat();

	Dog	firstDog;
	firstDog.getBrain()->setIdeas("I want to run!");
	std::cout << firstDog.getBrain()->getIdeas(0) << std::endl;
	firstDog.getBrain()->setIdeas("Oh, a rabit! I can catch it, I can catch it...");

	std::cout << "start of scope" << std::endl << std::endl;
	{
		Dog	tmp = firstDog;
	//	tmp.getBrain()->printIdea(0);
		std:: cout << "end of scope" << std::endl << std::endl;
	}
	std:: cout << "end of scope" << std::endl;
	

/*	Cat	catCopyTest;
	std::cout << "start of scope" << std::endl << std::endl;
	{
		Cat	tmp = catCopyTest;
		std:: cout << "end of scope" << std::endl << std::endl;
	}
	std:: cout << "end of scope" << std::endl; */

/*	const Animal*	animals[10];

	for (int i = 0; i < 10; i++) {
		if (i < 5)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	for (int i = 0; i < 10; i++)
		delete animals[i];*/

//	delete j;
//	delete i;
	

	
	return 0;
}