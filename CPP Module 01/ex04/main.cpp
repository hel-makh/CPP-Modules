/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 21:47:53 by hel-makh          #+#    #+#             */
/*   Updated: 2022/04/24 18:38:03 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

#include "strReplace.hpp"

int	main(int argc, char **argv) {
	std::ifstream	in_file;
	std::ofstream	out_file;
	
	if (argc != 4)
		return (std::cerr << "Error: Invalid arguments." << std::endl, EXIT_FAILURE);

	in_file.open(argv[1]);
	if (!in_file.is_open())
		return (std::cerr << "Error: Couldn't open <" << argv[1] << "> file." << std::endl, EXIT_FAILURE);

	std::string	out_file_name = argv[1];
	out_file.open(out_file_name + ".replace");
	if (!out_file.is_open())
		return (std::cerr << "Error: Couldn't open <" << argv[1] << ".replace> file." << std::endl, EXIT_FAILURE);
	
	std::string	str;
	while (std::getline(in_file, str)) {
		strReplace(str, argv[2], argv[3]);
		out_file << str;
		if (!in_file.eof())
			out_file << std::endl;
	}
	
	return (EXIT_SUCCESS);
}
