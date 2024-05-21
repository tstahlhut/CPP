/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 12:13:48 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/21 17:43:16 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/Intern.hpp"


void	WernerPlantsGarden( Bureaucrat Werner, Bureaucrat KH, AForm* garden) {

		std::cout << std::endl << "Hello, this me again:" << std::endl << std::endl;
		std::cout << Werner << std::endl << std::endl;
		std::cout << "Somehow I improved since we met last time ... " << std::endl << std::endl;

		std::cout << "Now I have an important task: plant a shrubbery for the president Zaphod Beeblebrox.";
		std::cout << "So, I start by getting the required form:" << std::endl << std::endl;
	
		std::cout << std::endl << garden << std::endl << std::endl;
		std::cout << "Great! Now, I execute the form ..." << std::endl << std::endl;
		Werner.executeForm(*garden);
		std::cout << std::endl << "... Ah, I have to sign it first ..." << std::endl << std::endl;
		Werner.signForm(*garden);
		std::cout << std::endl << "... now I can execute it ..." << std::endl << std::endl;
		Werner.executeForm(*garden);
		std::cout << std::endl << "Crap! So, " << Werner.getName() << " goes to his best colleague " << KH.getName();
		std::cout << " and asks him to execute it." << std::endl << std::endl;
		KH.executeForm(*garden);
		std::cout << std::endl;
		std::cout << "... and " << Werner.getName() << " planted the shrubbery - look into the garden ... ;)" << std::endl << std::endl;

		//ShrubberyCreationForm	garden2(garden);
	//	std::cout << garden2 << std::endl << std::endl;
		return ;
}

void	WernerRobotomizesHisTasks(Bureaucrat W, Bureaucrat K, AForm* form) {

	std::cout << std::endl << "Now that " << W.getName() << " made a wonderful garden, he wants to enjoy it.";
	std::cout << "So, he tries to robotomize his most important task: " << std::endl << std::endl;


	std::cout << std::endl;

	W.executeForm(*form);

	std::cout << std::endl << "... of course the form has to be signed first, how could he forget!" << std:: endl;
	std::cout << std::endl;

	W.signForm(*form);

	std::cout << std::endl << "Karl-Hermann is busy, so he asks his other collegue " << K.getName() << " ..." << std::endl;

	K.signForm(*form);

	std::cout << std::endl;

	W.executeForm(*form);

	std::cout << std::endl << "Oh, he has to ask her to execute it as well..." << std::endl;

	K.executeForm(*form);

	std::cout << std::endl;
	std::cout << "... and " << W.getName() << " sits 50% of the time happily in Zaphod Beeblebrox' garden :)" << std::endl;
	std::cout << std::endl;

	AForm*	form2(form);

	K.executeForm(*form2);

	std::cout << std::endl;
	std::cout << "... and " << W.getName() << " sits 100% of the time happily in Zaphod Beeblebrox' garden :)" << std::endl;
	std::cout << std::endl;

	return ;
}

void	KerstinRescuesWerner(Bureaucrat W, Bureaucrat K, Bureaucrat KH) {

	std::cout << std::endl;
	std::cout << "Now that " << W.getName() << " was but chilling in the garden, president Zaphod Beeblebrox got angry with him and put him into prison." << std::endl;
	std::cout << std::endl;
	std::cout << K.getName() << " cares for " << W.getName() << " and tries to get him out ..." << std::endl;
	std::cout << std::endl;
	
	PresidentialPardonForm	form("Werner");

	std::cout << form << std::endl << std::endl;

	K.signForm(form);

	K.executeForm(form);

	std::cout << std::endl;
	std::cout << K.getName() << " could sign the Presidential Pardon Form but not execute it." << std::endl;
	std::cout << K.getName() << " has only grade " << K.getGrade() << " ..." << std::endl << std::endl;
	std::cout << "So, she goes to see her husband " << KH.getName() << "..." << std::endl;

	std::cout << KH << std::endl;
	std::cout << std::endl;
	
	KH.executeForm(form);

	std::cout << std::endl;
	std::cout << W.getName() << " is such a lucky *** !" << std::endl << std::endl;

}

int	main( void ) {

	try 
	{
		Bureaucrat	Werner("Werner", 145);
		Bureaucrat	KH("Karl-Hermann", 1);
		Bureaucrat	Kerstin("Ulla", 25);
		Intern		TheIntern;

		std::cout << std::endl;

		AForm* form;
		
		form = TheIntern.makeForm("ShrubberyCreationForm", "garden");

		WernerPlantsGarden(Werner, KH, form);


		delete form;

	//	form = TheIntern.makeForm("RobotomyRequestForm", "sticking stamps");

	//	WernerRobotomizesHisTasks(Werner, Kerstin, form);

	//	KerstinRescuesWerner(Werner, Kerstin, KH);
		
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	
	return 0;
}
