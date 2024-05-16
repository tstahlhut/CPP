/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:31:20 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/16 11:54:45 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

int	main( void ) {

	// learn materias
	IMateriaSource*	src = new MateriaSource();

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	// create characters

	ICharacter*	Harry = new Character("Harry");
	ICharacter* Hermine = new Character("Hermine");
	ICharacter* Ron = new Character("Ron");
	ICharacter* troll = new Character("troll");
	
	// create materia and equip characters

	AMateria*	tmp;
	
	tmp = src->createMateria("ice");
	Harry->equip(tmp);
	tmp = src->createMateria("cure");
	Hermine->equip(tmp);


	// use equipment and equip more

	std::cout << Harry->getName() << " ";
	Harry->use(0, *troll);

	std::cout << Hermine->getName() << " ";
	Hermine->use(0, *Harry);

	tmp = src->createMateria("fire");
	Ron->equip(tmp);

	std::cout << Ron->getName() << ", ";
	Ron->use(0, *troll);

	std::cout << Hermine->getName() << " ";
	Hermine->use(0, *Ron);

	Hermine->equip(tmp);

	std::cout << Hermine->getName() << " ";
	Hermine->use(1, *troll);
	
	delete	Harry;
	delete	Ron;
	delete	Hermine;
	delete 	troll;
	delete	src;
	
}