/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 23:37:30 by hel-makh          #+#    #+#             */
/*   Updated: 2022/04/24 16:57:51 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::debug(void) {
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::info(void) {
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void	Harl::warning(void) {
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void) {
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::notfound(void) {
	std::cout << "Level not found." << std::endl;
}

Harl::Harl(void) {
	this->levels = new t_levels[5];

	this->levels[0].level = "DEBUG";
	this->levels[0].func = &Harl::debug;

	this->levels[1].level = "INFO";
	this->levels[1].func = &Harl::info;

	this->levels[2].level = "WARNING";
	this->levels[2].func = &Harl::warning;

	this->levels[3].level = "ERROR";
	this->levels[3].func = &Harl::error;

	this->levels[4].level = "NOTFOUND";
	this->levels[4].func = &Harl::notfound;
}

Harl::~Harl(void) {
	delete [] this->levels;
}

void	Harl::complain(std::string level) {
	int i;

	i = 0;
	while (i < 4 && this->levels[i].level.compare(level) != 0)
		i ++;

	(this->*(levels[i].func))();
}
