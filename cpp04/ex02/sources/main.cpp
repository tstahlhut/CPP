/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 14:42:59 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/15 13:32:40 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AAnimal.hpp"
#include "../includes/Brain.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"


void	testDogCopy( void ) {

	Dog	firstDog;
	firstDog.getBrain()->setIdeas("I want to run!");
	std::cout << "First dog: " << firstDog.getBrain()->getIdeas(0) << std::endl;
	firstDog.getBrain()->setIdeas("Oh, a rabit! I can catch it, I can catch it...");
	std::cout << "First dog: " << firstDog.getBrain()->getIdeas(1) << std::endl << std::endl;

	std::cout << "Copy first dog:" << std::endl;
	Dog	tmp = firstDog;	
	std::cout << "Copied dog: " << tmp.getBrain()->getIdeas(0) << std::endl;
	std::cout << "Copied dog: " << tmp.getBrain()->getIdeas(1) << std::endl << std::endl;

	std::cout << "The first dog forms a new idea: " << std::endl;
	firstDog.getBrain()->setIdeas("This is my own private idea...");
	std::cout << "First dog: " << firstDog.getBrain()->getIdeas(2) << std::endl << std::endl;

	std::cout << "But as I deep copied, the copied dog won't get it:" << std::endl;
	std::cout << "Copied dog: " << tmp.getBrain()->getIdeas(2) << std::endl << std::endl;

	return ;
}

void	testCatCopy( void ) {

	Cat	firstCat;
	firstCat.getBrain()->setIdeas("I want to go outside.");
	std::cout << "First Cat: " << firstCat.getBrain()->getIdeas(0) << std::endl;
	firstCat.getBrain()->setIdeas("Oh, a mouse!");
	std::cout << "First Cat: " << firstCat.getBrain()->getIdeas(1) << std::endl << std::endl;

	std::cout << "Copy first Cat:" << std::endl;
	Cat	secondCat = firstCat;	
//	Cat	secondCat( firstCat );
	std::cout << "Second Cat: " << secondCat.getBrain()->getIdeas(0) << std::endl;
	std::cout << "Second Cat: " << secondCat.getBrain()->getIdeas(1) << std::endl << std::endl;

	std::cout << "The first Cat forms a new idea: " << std::endl;
	firstCat.getBrain()->setIdeas("This is my own private idea of how I can get a human to pet me...");
	std::cout << "First Cat: " << firstCat.getBrain()->getIdeas(2) << std::endl << std::endl;

	std::cout << "But as I deep copied, the copied Cat won't get it:" << std::endl;
	std::cout << "Second Cat: " << secondCat.getBrain()->getIdeas(2) << std::endl << std::endl;
	

	return ;

}

void	testArray( void ) {

	const AAnimal*	animals[10];

	for (int i = 0; i < 4; i++) {
		if (i < 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	for (int i = 0; i < 4; i++) {
		std::cout << "I'm a " << animals[i]->getType() << " and I ";
		animals[i]->makeSound();
	}

	for (int i = 0; i < 4; i++)
		delete animals[i];

	return ;
}

int	main( void ) {

//	testDogCopy();

//	testCatCopy();
	
	testArray();

//	AAnimal anAnimal;
	

	return 0;
}