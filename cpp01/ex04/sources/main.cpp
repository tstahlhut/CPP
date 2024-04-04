/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42berlin.de>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-04-04 07:38:29 by tstahlhu          #+#    #+#             */
/*   Updated: 2024-04-04 07:38:29 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int openFiles(const std::string& infile, const std::string& outfile, std::ifstream& infileStream, std::ofstream& outfileStream)
{
	infileStream.open(infile.c_str());
	if (!infileStream.is_open())
	{
		std::cerr << "Failed to open file " << infile << std::endl;
		return (0);
	}
	outfileStream.open(outfile.c_str());
	if (!outfileStream.is_open())
	{
		std::cerr << "Failed to open file " << outfile << std::endl;
		return (0);
	}
	return (1);
}

int	replace(const std::string& infile)
{
	std::string outfile;
	std::ifstream infileStream;
	std::ofstream outfileStream;
	
	outfile = infile;
	outfile.append(".replace");
	if (!openFiles(infile, outfile, infileStream, outfileStream))
		return (1);
	return (0);	
}


int	main(int argc, char **argv)
{

	if (argc != 4)
	{
		std::cout << "Program needs 3 arguments: filename, string, string" << std::endl;
		return (0);
	}
	return (replace(argv[1]));
}