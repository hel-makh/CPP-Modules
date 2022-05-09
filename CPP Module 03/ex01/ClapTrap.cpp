/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 15:10:46 by hel-makh          #+#    #+#             */
/*   Updated: 2022/05/09 13:35:14 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/*************************[ Constructors/Destructors ]*************************/

ClapTrap::ClapTrap(void) :	_hitPoints(10),
							_energyPoints(10),
							_attackDamage(0) {
	std::cout << "ClapTrap Default constructor called." << std::endl;
	return ;
}

ClapTrap::ClapTrap(std::string	name) :	_name(name),
										_hitPoints(10),
										_energyPoints(10),
										_attackDamage(0) {
	std::cout << "ClapTrap Name constructor called." << std::endl;
	return ;
}

ClapTrap::ClapTrap(ClapTrap const & rhs) {
	std::cout << "ClapTrap Copy constructor called." << std::endl;
	*this = rhs;
	return ;
}

ClapTrap::~ClapTrap(void) {
	std::cout << "ClapTrap Destructor called." << std::endl;
	return ;
}

/****************************[ Operators overload ]****************************/

ClapTrap &	ClapTrap::operator=(ClapTrap const & rhs) {
	std::cout << "ClapTrap Copy assignment operator called." << std::endl;
	this->setName(rhs.getName());
	this->setHitPoints(rhs.getHitPoints());
	this->setEnergyPoints(rhs.getEnergyPoints());
	this->setAttackDamage(rhs.getAttackDamage());
	return (*this);
}

/*****************************[ Member Functions ]*****************************/

std::string	ClapTrap::getName(void) const {
	return (this->_name);
}

int	ClapTrap::getHitPoints(void) const {
	return (this->_hitPoints);
}

int	ClapTrap::getEnergyPoints(void) const {
	return (this->_energyPoints);
}

int	ClapTrap::getAttackDamage(void) const {
	return (this->_attackDamage);
}

void	ClapTrap::setName(std::string name) {
	this->_name = name;
}

void	ClapTrap::setHitPoints(int hitPoints) {
	this->_hitPoints = hitPoints;
}

void	ClapTrap::setEnergyPoints(int energyPoints) {
	this->_energyPoints = energyPoints;
}

void	ClapTrap::setAttackDamage(int attackDamage) {
	this->_attackDamage = attackDamage;
}

void	ClapTrap::attack(const std::string & target) {
	if (this->getEnergyPoints() - 1 < 0 || this->getHitPoints() <= 0)
		return ;
	std::cout << "ClapTrap " << this->getName() << " attacks " << target << ", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
	this->setEnergyPoints(this->getEnergyPoints() - 1);
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (this->getHitPoints() <= 0)
		return ;
	std::cout << "ClapTrap " << this->getName() << " took " << amount << " points of damage!" << std::endl;
	this->setHitPoints(this->getHitPoints() - amount);
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->getEnergyPoints() - 1 < 0 || this->getHitPoints() <= 0)
		return ;
	std::cout << "ClapTrap " << this->getName() << " repaired itself, restoring " << amount << " hit points!" << std::endl;
	this->setHitPoints(this->getHitPoints() + amount);
	this->setEnergyPoints(this->getEnergyPoints() - 1);
}
