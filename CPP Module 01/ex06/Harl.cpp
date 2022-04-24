/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 23:37:30 by hel-makh          #+#    #+#             */
/*   Updated: 2022/04/24 17:29:21 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::debug(void) {
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl << std::endl;
}

void	Harl::info(void) {
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl << std::endl;
}

void	Harl::warning(void) {
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl << std::endl;
}

void	Harl::error(void) {
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl << std::endl;
}

void	Harl::notfound(void) {
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}

Harl::Harl(void) {
	this->levels = new t_levels[5];

	this->levels[0].level = "DEBUG";
	this->levels[1].level = "INFO";
	this->levels[2].level = "WARNING";
	this->levels[3].level = "ERROR";
	this->levels[4].level = "NOTFOUND";
}

Harl::~Harl(void) {
	delete [] this->levels;
}

void	Harl::complain(std::string level) {
	int lvl;

	lvl = 0;
	while (lvl < 4 && this->levels[lvl].level.compare(level) != 0)
		lvl ++;

	switch (lvl) {
		case 0:
			this->debug();
		case 1:
			this->info();
		case 2:
			this->warning();
		case 3:
			this->error();
			break ;
		default:
			this->notfound();
	}
}
