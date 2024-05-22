/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 12:13:48 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/22 11:23:11 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/Intern.hpp"


void	WernerPlantsGarden( Bureaucrat Werner, Bureaucrat KH, AForm* form) {

		std::cout << std::endl << *form << std::endl << std::endl;

		std::cout << "Great! Now, I just sign the form ..." << std::endl << std::endl;
	
		Werner.signForm(*form);
		std::cout << std::endl << "... and give it to "  << KH.getName() << " to execute it:" << std::endl << std::endl;
	
		KH.executeForm(*form);
		std::cout << std::endl;
		std::cout << "... and done! Look into company backyard ... ;)" << std::endl << std::endl;

		return ;
}

void	WernerRobotomizesHisTasks(Bureaucrat K, AForm* form) {

	
	std::cout << std::endl << *form << std::endl << std::endl;

	std::cout << "This is so nice! Now, I just ask " << K.getName() << " to sign and execute the form ..." << std::endl << std::endl;

	K.signForm(*form);

	K.executeForm(*form);
	
	std::cout << std::endl;

	return ;
}

void	Pardon(Bureaucrat K, Bureaucrat KH, AForm* form) {

	std::cout << std::endl;

	std::cout << *form << std::endl << std::endl;

	std::cout << "Of course " << KH.getName() << " will ask somebody else to sign it: " << std::endl << std::endl;

	K.signForm(*form);

	std::cout << "... now " << KH.getName() << " can execute the form:" << std::endl << std::endl;

	KH.executeForm(*form);

	std::cout << std::endl;

}

int	main( void ) {

	AForm* form[3];
	try 
	{
		Bureaucrat	Werner("Werner", 145);
		Bureaucrat	KH("Karl-Hermann", 1);
		Bureaucrat	Kerstin("Ulla", 25);
		Intern		TheIntern;

		std::cout << std::endl;

		std::cout << "From now on " << Werner.getName() << "'s life becomes even nicer: An Intern has come to the company. ";
		std::cout << "From now on, " << Werner.getName() << " asks the Intern to create the forms for him:" << std::endl << std::endl;

		
	//1
		form[0] = TheIntern.makeForm("ShrubberyCreationForm", "company");

		WernerPlantsGarden(Werner, Kerstin, form[0]);

	//2
		form[1] = TheIntern.makeForm("RobotomyRequestForm", "send e-mail");

		WernerRobotomizesHisTasks(Kerstin, form[1]);		

	//3
		std::cout << KH.getName() << " was impressed by " << Werner.getName() << "'s productivity and calls the Intern, too:" << std::endl;

		form[2] = TheIntern.makeForm("PresidentialPardonForm", "Some random dude");

		Pardon(Kerstin, KH, form[2]);

	// delete allocated memory
		for (int i = 0; i < 3; i++) {
			delete form[i];
		}
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
		// delete allocated memory
		for (int i = 0; i < 3; i++) {
			delete form[i];
		}
	}	
	return 0;
}
