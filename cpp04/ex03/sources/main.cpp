/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:31:20 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/16 15:28:38 by tstahlhu         ###   ########.fr       */
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

	AMateria*	m1 = src->createMateria("ice");
	AMateria*	m2 = src->createMateria("ice");
	AMateria*	m3 = src->createMateria("cure");
	AMateria*	m4 = src->createMateria("cure");
	AMateria*	m5 = src->createMateria("cure");
	AMateria*	tmp;

	Harry->equip(m1);
	Hermine->equip(m2);
	Ron->equip(m3);
	
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

	tmp = src->createMateria("cure");
	Hermine->equip(tmp);

	std::cout << Hermine->getName() << " ";
	Hermine->use(1, *troll);

	Hermine->unequip(2);
	
	delete	Harry;
	delete	Ron;
	delete	Hermine;


	Character* em = new Character("EM");
	em->equip(tmp);
	em->use(0, *troll);
	Character* copy = new Character(*em);
	//em->unequip(0);
	copy->use(0, *troll);

	delete 	troll;
	delete	src;
	
	// delete materias which are not in use
	delete	m4;
	delete	m5;


}