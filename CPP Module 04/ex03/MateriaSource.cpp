/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 17:01:44 by hel-makh          #+#    #+#             */
/*   Updated: 2022/05/15 13:04:04 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

/*************************[ Constructors/Destructors ]*************************/

MateriaSource::MateriaSource(void) {
	for (int i = 0; i < MAXSLOTS; i ++) {
		this->_inventory[i] = nullptr;
	}
}

MateriaSource::MateriaSource(MateriaSource const & rhs) {
	new (this) MateriaSource();
	for (int i = 0; i < MAXSLOTS; i ++) {
		if (rhs._inventory[i])
			this->_inventory[i] = rhs._inventory[i]->clone();
	}
}

MateriaSource::~MateriaSource(void) {
	for (int i = 0; i < MAXSLOTS; i ++) {
		if (!this->_inventory[i])
			continue ;
		delete this->_inventory[i];
		this->_inventory[i] = nullptr;
	}
}

/****************************[ Operators overload ]****************************/

MateriaSource &	MateriaSource::operator=(MateriaSource const & rhs) {
	if (this != &rhs) {
		this->~MateriaSource();
		new (this) MateriaSource(rhs);
	}
	return (*this);
}

/*****************************[ Member Functions ]*****************************/

void	MateriaSource::learnMateria(AMateria * m) {
	for (int i = 0; i < MAXSLOTS; i ++) {
		if (!this->_inventory[i]) {
			this->_inventory[i] = m;
			break ;
		}
	}
}

AMateria *	MateriaSource::createMateria(std::string const & type) {
	AMateria *	newMateria;
	
	for (int i = MAXSLOTS - 1; i >= 0; i --) {
		if (this->_inventory[i] && this->_inventory[i]->getType() == type) {
			newMateria = this->_inventory[i]->clone();
			return (newMateria);
		}
	}
	return (0);
}
