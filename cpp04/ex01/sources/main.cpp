/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 14:42:59 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/11 16:56:57 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/Cat.hpp"
#include "../includes/WrongCat.hpp"
#include "../includes/Dog.hpp"

int	main( void ) {

	const Animal*		meta = new Animal();
	const Dog*			NormalDog = new Dog();
	const Cat*			NormalCat = new Cat();

	std::cout << std::endl << "This exercise is about polymorphism :)" << std::endl;

	std::cout << "An Animal will make ..." << std::endl;
	meta->makeSound();

	std::cout << std::endl << "A Dog will ..." << std::endl;
	NormalDog->makeSound();

	std::cout << std::endl << "and a Cat will ..." << std::endl;
	NormalCat->makeSound();


	std::cout << std::endl << "But what if ..." << std::endl << std::endl;

	const Animal*		DogAnimal = new Dog();
	const Animal*		CatAnimal = new Cat();
	const WrongAnimal*	WrongCatAnimal = new WrongCat();

	std::cout << std::endl << "... you have a Dog of type Animal, it should bark and not make an animal sound:" << std::endl;
	
	std::cout << DogAnimal->getType() << " " << std::endl;
	DogAnimal->makeSound();

	std::cout << std::endl << "And if you have a Cat of type Animal, it should meow and not make an animal sound:" << std::endl;
	std::cout << CatAnimal->getType() << " " << std::endl;
	CatAnimal->makeSound();


	std::cout << std::endl << "If you get that wrong and do not use the keyword 'virtual' your cat will make ..." << std::endl;
	WrongCatAnimal->makeSound();
	std::cout << std::endl;
	
	return 0;
}