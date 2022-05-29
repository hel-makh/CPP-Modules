/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 15:37:11 by hel-makh          #+#    #+#             */
/*   Updated: 2022/05/29 16:39:22 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

#include "easyfind.hpp"

int	main(void) {
	std::vector<int>			vec;
	std::vector<int>::iterator	it;

	for (int i = 0; i < 5; i ++)
		vec.push_back(i);

	try {
		it = easyfind< std::vector<int> >(vec, 4);
		std::cout << "Element found: " << *it << std::endl;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	try {
		it = easyfind< std::vector<int> >(vec, 6);
		std::cout << "Element found: " << *it << std::endl;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	
	return (EXIT_SUCCESS);
}
