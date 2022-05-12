/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:18:44 by hel-makh          #+#    #+#             */
/*   Updated: 2022/05/12 13:34:27 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int	main(void) {
	const AAnimal	*animals[10];
	
	for (int i = 0; i < 5; i++) {
		animals[i] = new Dog();
	}
	
	for (int i = 5; i < 10; i++) {
		animals[i] = new Cat();
	}
	
	for (int i = 0; i < 5; i++) {
		animals[i]->makeSound();
		std::cout << ((Dog *)animals[i])->getBrain()->getIdeas()[0] << std::endl;
	}
	
	for (int i = 5; i < 10; i++) {
		animals[i]->makeSound();
		std::cout << ((Cat *)animals[i])->getBrain()->getIdeas()[0] << std::endl;
	}

	for (int i = 9; i >= 0; i--) 
		delete animals[i];
	
	return 0;
}
