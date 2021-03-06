/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:01:10 by hel-makh          #+#    #+#             */
/*   Updated: 2022/06/01 15:24:16 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

/*************************[ Constructors/Destructors ]*************************/

DiamondTrap::DiamondTrap(void) {
	std::cout << "DiamondTrap Default constructor called." << std::endl;
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(30);
	return ;
}

DiamondTrap::DiamondTrap(std::string name) : _name(name) {
	std::cout << "DiamondTrap Name constructor called." << std::endl;
	this->ClapTrap::setName(name + "_clap_name");
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(30);
	return ;
}

DiamondTrap::DiamondTrap(DiamondTrap const & rhs) {
	std::cout << "DiamondTrap Copy constructor called." << std::endl;
	*this = rhs;
	return ;
}

DiamondTrap::~DiamondTrap(void) {
	std::cout << "DiamondTrap Destructor called." << std::endl;
	return ;
}

/****************************[ Operators overload ]****************************/

DiamondTrap &	DiamondTrap::operator=(DiamondTrap const & rhs) {
	std::cout << "DiamondTrap Copy assignment operator called." << std::endl;
	this->setName(rhs.getName());
	this->setHitPoints(rhs.getHitPoints());
	this->setEnergyPoints(rhs.getEnergyPoints());
	this->setAttackDamage(rhs.getAttackDamage());
	this->ClapTrap::setName(rhs.ClapTrap::getName());
	this->ClapTrap::setHitPoints(rhs.ClapTrap::getHitPoints());
	this->ClapTrap::setEnergyPoints(rhs.ClapTrap::getEnergyPoints());
	this->ClapTrap::setAttackDamage(rhs.ClapTrap::getAttackDamage());
	return (*this);
}

/*****************************[ Member Functions ]*****************************/

std::string	DiamondTrap::getName(void) const {
	return (this->_name);
}

void	DiamondTrap::setName(std::string name) {
	this->_name = name;
	this->ClapTrap::setName(name + "_clap_name");
}

void	DiamondTrap::whoAmI(void) {
	std::cout << "ClapTrap name: " << this->ClapTrap::getName() << std::endl;
	std::cout << "DiamondTrap name: " << this->_name << std::endl;
}
