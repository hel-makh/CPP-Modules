/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:01:10 by hel-makh          #+#    #+#             */
/*   Updated: 2022/05/15 15:21:44 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

/*************************[ Constructors/Destructors ]*************************/

DiamondTrap::DiamondTrap(void) {
	std::cout << "DiamondTrap Default constructor called." << std::endl;
	this->setHitPoints(this->FragTrap::getHitPoints());
	this->setEnergyPoints(this->ScavTrap::getEnergyPoints());
	this->setAttackDamage(this->FragTrap::getAttackDamage());
	return ;
}

DiamondTrap::DiamondTrap(std::string name) : _name(name) {
	std::cout << "DiamondTrap Name constructor called." << std::endl;
	this->ClapTrap::setName(name + "_clap_name");
	this->setHitPoints(this->FragTrap::getHitPoints());
	this->setEnergyPoints(this->ScavTrap::getEnergyPoints());
	this->setAttackDamage(this->FragTrap::getAttackDamage());
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

void	DiamondTrap::attack(const std::string & target) {
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void) {
	std::cout << "ClapTrap name: " << this->ClapTrap::getName() << std::endl;
	std::cout << "DiamondTrap name: " << this->_name << std::endl;
}
