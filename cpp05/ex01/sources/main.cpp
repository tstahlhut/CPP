/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 12:13:48 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/17 17:28:04 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"




int	main( void ) {

	try 
	{
		//A. Instantiate Bureaucrats

		Bureaucrat	Werner("Werner", 150);
		Bureaucrat	KH("Karl-Hermann", 1);

		std::cout << std::endl;
		std::cout << "Hello, this me again:" << std::endl << std::endl;
		std::cout << Werner << std::endl;
		std::cout << std::endl;

		std::cout << Werner.getName() << " wants to go to the toilet. So, he instantiates the required form:" << std::endl;
		//B. Instantiate Forms

		Form	toilet("Toilet", 100, 50);

		std::cout << toilet << std::endl << std::endl;
		std::cout << "... and tries to sign it himself ..." << std::endl << std::endl;
		Werner.signForm(toilet);
		std::cout << "Crap! So, " << Werner.getName() << " goes to " << KH.getName();
		std::cout << " and asks him to sign it." << std::endl << std::endl;
		std::cout << KH << std::endl;
		KH.signForm(toilet);
		std::cout << toilet << std::endl << std::endl;
		std::cout << "... and " << Werner.getName() << " can continue his business :)" << std::endl << std::endl;

		std::cout << "... and because " << Werner.getName();
		std::cout << " is not dumb, he copies the signed form for his next toilet visit:" << std::endl << std::endl;

		Form	toilet2(toilet);
		std::cout << toilet2 << std::endl << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	// you could also specify the exceptions:
/*	catch (Bureaucrat::GradeTooLowException e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}*/
	return 0;
}
