/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 13:01:10 by hel-makh          #+#    #+#             */
/*   Updated: 2022/05/09 13:33:20 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/*************************[ Constructors/Destructors ]*************************/

FragTrap::FragTrap(void) {
	std::cout << "FragTrap Default constructor called." << std::endl;
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
	return ;
}

FragTrap::FragTrap(std::string	name) {
	std::cout << "FragTrap Name constructor called." << std::endl;
	this->setName(name);
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
	return ;
}

FragTrap::FragTrap(FragTrap const & rhs) {
	std::cout << "FragTrap Copy constructor called." << std::endl;
	*this = rhs;
	return ;
}

FragTrap::~FragTrap(void) {
	std::cout << "FragTrap Destructor called." << std::endl;
	return ;
}

/****************************[ Operators overload ]****************************/

FragTrap &	FragTrap::operator=(FragTrap const & rhs) {
	std::cout << "FragTrap Copy assignment operator called." << std::endl;
	this->setName(rhs.getName());
	this->setHitPoints(rhs.getHitPoints());
	this->setEnergyPoints(rhs.getEnergyPoints());
	this->setAttackDamage(rhs.getAttackDamage());
	return (*this);
}

/*****************************[ Member Functions ]*****************************/

void	FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap wants a high five!" << std::endl;
}
