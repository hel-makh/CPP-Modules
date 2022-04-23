/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 21:47:53 by hel-makh          #+#    #+#             */
/*   Updated: 2022/04/23 22:43:34 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

int	main(int argc, char **argv) {
	std::ifstream	in_file;
	std::ofstream	out_file;

	if (argc < 4 || argc > 4)
		return (std::cout << "Error: Invalid arguments." << std::endl, EXIT_FAILURE);

	in_file.open(argv[1]);
	if (!in_file.is_open())
		return (std::cout << "Error: Couldn't open <" << argv[1] << "> file." << std::endl, EXIT_FAILURE);

	std::string	out_file_name = argv[1];
	out_file.open(out_file_name + ".replace");
	if (!out_file.is_open())
		return (std::cout << "Error: Couldn't open <" << argv[1] << ".replace> file." << std::endl, EXIT_FAILURE);

	char	c;
	int		i = 0;
	while (in_file.get(c)) {
		if (c == argv[2][i]) {
			i ++;
			if (argv[2][i] == '\0') {
				out_file << argv[3];
				i = 0;
			}
			continue ;
		}
		out_file << c;
	}

	return (EXIT_SUCCESS);
}
