/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 07:38:29 by tstahlhu          #+#    #+#             */
/*   Updated: 2024/04/30 13:02:42 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int openFiles(const std::string& infile, const std::string& outfile, std::ifstream& in, std::ofstream& out)
{
	//opens infile
	if (!in.is_open())
	{
		std::cerr << "Error: failed to open infile: " << infile << std::endl;
		return (0);
	}
	//opens outfile
	if (!out.is_open())
	{
		in.close();
		std::cerr << "Error: failed to open outfile: " << outfile << std::endl;
		return (0);
	}
	return (1);
}

int	replace(const char* infile, const std::string& word1, const std::string& word2)
{
	//open infile
	std::ifstream in(infile);
	

	//create outfile name
	std::string outfile = infile;
	outfile.append(".replace");

	//open outfile
	std::ofstream out(outfile.c_str());

	//check if open failed
	if (!openFiles(infile, outfile, in, out))
		return (1);

	//read from infile with ifstream and getline into buffer
	std::string buf;
	std::string::size_type	w; //word position
	while (std::getline(in, buf))
	{
		w = buf.find(word1);
		while (std::string::npos != w)  //npos = last bit any string can have
		{
			buf.erase(w, word1.length());
			buf.insert(w, word2);
			w = buf.find(word1);
		}
		// write to file with ofstream
		out << buf;
		out << "\n";
	}
	if (!buf.length())
		std::cout << "Warning: infile empty: " << infile << std::endl;
	//ifstream and ofstream normally close stream themselves
	in.close();
	out.close();
	return (0);	
}


int	main(int argc, char **argv)
{

	if (argc != 4)
	{
		std::cout << "Program needs 3 arguments: filename, string, string" << std::endl;
		return (0);
	}
	return (replace(argv[1], argv[2], argv[3]));
}