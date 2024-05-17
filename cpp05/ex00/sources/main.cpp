/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 12:13:48 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/17 15:23:28 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

void	createWrongBureaucrats( void ) {

		//Bureaucrat	Heinz("Heinz", 151);
		//Bureaucrat	Heiner("Heiner", 0);
		Bureaucrat	Werner("Werner", 150);
		Bureaucrat	KH("Karl-Hermann", 1);

}


int	main( void ) {

	try 
	{
		//A. Instantiate Bureaucrats

		// 1. Test exception at construction
		//Bureaucrat	Heinz("Heinz", 151);
		//Bureaucrat	Heiner("Heiner", 0);

		// normal instantiation
		Bureaucrat	Werner("Werner", 148);
		Bureaucrat	KH("Karl-Hermann", 2);

		std::cout << std::endl;
		std::cout << KH << std::endl;

		//B. Increment Grades
		std::cout << "'Well done, " << KH.getName() << "! You get promoted!'" << std::endl;
		KH.incrementGrade();
		std::cout << KH << std::endl;

		// 2. Test exception when incremented above 1
		//KH.incrementGrade();
		//std::cout << KH << std::endl;

		std::cout << std::endl;

		//C. Decrement Grades
		std::cout << Werner << std::endl;
		std::cout << "'Oh, " << Werner.getName() << "! What did you do?! You better do it again...'" << std::endl;
		Werner.decrementGrade();
		std::cout << Werner << std::endl;
		std::cout << "'Oh," << Werner.getName() << "! Not again! You will be degraded!'" << std::endl;
		Werner.decrementGrade();
		std::cout << Werner << std::endl;
		
		// 3. Test exception when decremented under 150
		//std::cout << "'WTF " << Werner.getName() << "?!! De-'" << std::endl; 
		//Werner.decrementGrade();
		//std::cout << Werner << std::endl;
		std::cout << std::endl;

		std::cout << "This is when " << Werner.getName();
		std::cout << " is so demotivated that he copies from bureaucratic superstar " << KH.getName();
		std::cout << " ..." << std::endl;
		Werner = KH;
		std::cout << Werner << std::endl;

		std::cout << "'Oh, " << Werner.getName() << "! What did you do?!'" << std::endl;
		Werner.decrementGrade();
		std::cout << Werner << std::endl << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	return 0;
}