/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:33:10 by vm                #+#    #+#             */
/*   Updated: 2024/02/26 09:27:05 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream> /*standard library: input output stream*/
#include <string> /*for toupper function*/
/* C++ Basics:
	- to print something use standard character output: 
		std for the standard library
		specify with ::
		character out: cout
	- you can also specify the standard library as a namespace in the beginning
		(this implies that you do not use any name used in the namespace for
		your own functions and variables)
		using namespace std;


	- as in C, terminate each statement with a ;
 * with bitwise shift left and a string literal to output.*/

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	while (argc > 1 && ++i < argc)
	{
		j = -1;
		while (argv[i][++j] != '\0')
			std::cout << (char)std::toupper(argv[i][j]);
	}
	std::cout << std::endl;
	return (0);
}