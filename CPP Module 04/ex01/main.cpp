/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:18:44 by hel-makh          #+#    #+#             */
/*   Updated: 2022/05/11 11:42:45 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int	main(void) {
	const Animal	*animals[10];
	
	for (int i = 0; i < 5; i++) {
		animals[i] = new Dog();
	}
	
	for (int i = 5; i < 10; i++) {
		animals[i] = new Cat();
	}

	for (int i = 0; i < 10; i++) {
		animals[i]->makeSound();
		// std::cout << animals[i]->getBrain()->getIdeas()[0] << std::endl;
		// std::cout << animals[i]->getBrain()->getIdeas()[1] << std::endl;
	}

	for (int i = 9; i >= 0; i--) 
		delete animals[i];
	
	return 0;
}
