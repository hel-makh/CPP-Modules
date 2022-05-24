/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 15:27:00 by hel-makh          #+#    #+#             */
/*   Updated: 2022/05/24 15:36:30 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Data.hpp"
#include "Serialization.hpp"

int	main(void) {
	Data 		*data;
	uintptr_t	ptr;

	data = new Data();

	std::cout << "Before:" << std::endl;
	std::cout << data->getChar() << std::endl;
	std::cout << data->getInt() << std::endl;
	std::cout << data->getFloat() << std::endl;
	std::cout << data->getDouble() << std::endl;

	ptr = serialize(data);
	data = deserialize(ptr);
	
	std::cout << std::endl << "After:" << std::endl;
	std::cout << data->getChar() << std::endl;
	std::cout << data->getInt() << std::endl;
	std::cout << data->getFloat() << std::endl;
	std::cout << data->getDouble() << std::endl;
	
	return (EXIT_SUCCESS);
}
