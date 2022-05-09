/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 13:01:10 by hel-makh          #+#    #+#             */
/*   Updated: 2022/05/09 13:24:04 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/*************************[ Constructors/Destructors ]*************************/

ScavTrap::ScavTrap(void) {
	std::cout << "ScavTrap Default constructor called." << std::endl;
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
	return ;
}

ScavTrap::ScavTrap(std::string	name) {
	std::cout << "ScavTrap Name constructor called." << std::endl;
	this->setName(name);
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
	return ;
}

ScavTrap::ScavTrap(ScavTrap const & rhs) {
	std::cout << "ScavTrap Copy constructor called." << std::endl;
	*this = rhs;
	return ;
}

ScavTrap::~ScavTrap(void) {
	std::cout << "ScavTrap Destructor called." << std::endl;
	return ;
}

/****************************[ Operators overload ]****************************/

ScavTrap &	ScavTrap::operator=(ScavTrap const & rhs) {
	std::cout << "ScavTrap Copy assignment operator called." << std::endl;
	this->setName(rhs.getName());
	this->setHitPoints(rhs.getHitPoints());
	this->setEnergyPoints(rhs.getEnergyPoints());
	this->setAttackDamage(rhs.getAttackDamage());
	return (*this);
}

/*****************************[ Member Functions ]*****************************/

void	ScavTrap::attack(const std::string & target) {
	if (this->getEnergyPoints() - 1 < 0 || this->getHitPoints() <= 0)
		return ;
	std::cout << "ScavTrap " << this->getName() << " attacks " << target << ", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
	this->setEnergyPoints(this->getEnergyPoints() - 1);
}

void	ScavTrap::guardGate(void) {
	std::cout << "ScavTrap is now in Gate keeper mode!" << std::endl;
}
