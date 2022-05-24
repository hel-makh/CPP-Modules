/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 15:46:47 by hel-makh          #+#    #+#             */
/*   Updated: 2022/05/24 16:16:59 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identify.hpp"

Base *	generate(void) {
	srand(time(NULL));
	switch (rand() % 3 + 1) {
		case 1:
			std::cout << "Generated A Type" << std::endl;
			return (new A());
		case 2:
			std::cout << "Generated B Type" << std::endl;
			return (new B());
		case 3:
			std::cout << "Generated C Type" << std::endl;
			return (new C());
	}
	return (nullptr);
}

void	identify(Base * p) {
	if (dynamic_cast<A *>(p) != nullptr) {
		std::cout << "This object is A Type" << std::endl;
		return ;
	}
	if (dynamic_cast<B *>(p) != nullptr) {
		std::cout << "This object is B Type" << std::endl;
		return ;
	}
	if (dynamic_cast<C *>(p) != nullptr) {
		std::cout << "This object is C Type" << std::endl;
		return ;
	}
}

void	identify(Base & p) {
	std::string	classes = "ABC";

	for (size_t i = 0; i < classes.length(); i ++) {
		try {
			if (classes[i] == 'A') {
				(void)dynamic_cast<A &>(p);
				std::cout << "This object is A Type" << std::endl;
			}
			else if (classes[i] == 'B') {
				(void)dynamic_cast<B &>(p);
				std::cout << "This object is B Type" << std::endl;
			}
			else if (classes[i] == 'C') {
				(void)dynamic_cast<C &>(p);
				std::cout << "This object is C Type" << std::endl;
			}
		}
		catch (std::exception & e) {}
	}
}
