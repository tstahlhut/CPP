/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:08:20 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/05/03 13:22:31 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	Harl	Harl1;
	
	std::string level[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	
	int	i;
	
	if (argc == 2)
	{
		std::string input = argv[1];

		i = -1;
		while (++i < 4)
		{
			if (input == level[i])
				break;
		}

		switch (i)
		{
			case 0:
				std::cout << "[ " << level[0] << " ]" << std::endl;
				Harl1.complain(level[0]);
				std::cout << std::endl;
			case 1:
				std::cout << "[ " << level[1] << " ]" << std::endl;
				Harl1.complain(level[1]);
				std::cout << std::endl;
			case 2:
				std::cout << "[ " << level[2] << " ]" << std::endl;
				Harl1.complain(level[2]);
				std::cout << std::endl;
			case 3:
				std::cout << "[ " << level[3] << " ]" << std::endl;
				Harl1.complain(level[3]);
				std::cout << std::endl;
				break;
			default:
				std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		}
	}
	else
		std::cout << "Input a level of complaint. Only one level allowed." << std::endl;
	return (0);
}