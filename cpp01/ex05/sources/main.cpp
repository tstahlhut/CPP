/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:08:20 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/03 12:29:26 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	Harl	Harl1;

	if (argc > 1)
	{
		for (int i = 1; i < argc; i++)
			Harl1.complain(argv[i]);		
	}
	else
	{
		std::cout << "Sahara: 'Which sauce, please?'" << std::endl;
		Harl1.complain("DEBUG");
		std::cout << "Sahara: 'Here you are!'" << std::endl;
		Harl1.complain("INFO");
		std::cout << "Sahara: 'Here, you see the peanut sauce, there it is.'" << std::endl;
		Harl1.complain("WARNING");
		std::cout << "Sahara: '[LAUGHING]'" << std::endl;
		Harl1.complain("ERROR");
		std::cout << "Sahara: 'That is me ;)'" << std::endl;
	}
	return (0);
}