/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 13:01:48 by hel-makh          #+#    #+#             */
/*   Updated: 2022/05/15 13:02:38 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

/*************************[ Constructors/Destructors ]*************************/

Character::Character(std::string const name) :	_name(name) {
	for (int i = 0; i < MAXSLOTS; i ++) {
		this->_inventory[i] = nullptr;
	}
	this->_dropped = new AMateria*[1];
	this->_dropped[0] = nullptr;
}

Character::Character(Character const & rhs) {
	new (this) Character(rhs.getName());
	for (int i = 0; i < MAXSLOTS; i ++) {
		if (rhs._inventory[i])
			this->_inventory[i] = rhs._inventory[i]->clone();
	}
}

Character::~Character(void) {
	for (int i = 0; i < MAXSLOTS; i ++) {
		if (!this->_inventory[i])
			continue ;
		delete this->_inventory[i];
		this->_inventory[i] = nullptr;
	}
	int	dropedSize = this->droppedSize();
	for (int i = 0; i < dropedSize; i ++) {
		delete this->_dropped[i];
		this->_dropped[i] = nullptr;
	}
	delete [] this->_dropped;
}

/****************************[ Operators overload ]****************************/

Character &	Character::operator=(Character const & rhs) {
	if (this != &rhs) {
		this->~Character();
		new (this) Character(rhs);
	}
	return (*this);
}

/*****************************[ Member Functions ]*****************************/

int	Character::droppedSize(void) const {
	int	len;

	len = 0;
	while (this->_dropped[len])
		len ++;
	return (len);
}

void	Character::storeMateria(AMateria & Object) {
	AMateria ** newClones;
	int			objSize;
	int 		i;

	objSize = this->droppedSize() + 2;
	
	newClones = new AMateria*[objSize];
	for (i = 0; i < objSize - 2; i ++) {
		newClones[i] = this->_dropped[i];
	}
	newClones[i ++] = &Object;
	newClones[i] = nullptr;
	delete [] this->_dropped;

	this->_dropped = new AMateria*[objSize];
	for (i = 0; i < objSize; i ++) {
		this->_dropped[i] = newClones[i];
	}
	delete [] newClones;
}

std::string const &	Character::getName(void) const {
	return (this->_name);
}

void	Character::setName(std::string const name) {
	this->_name = name;
}

void	Character::equip(AMateria * m) {
	for (int i = 0; i < MAXSLOTS; i ++) {
		if (!this->_inventory[i]) {
			this->_inventory[i] = m;
			break ;
		}
	}
}

void	Character::unequip(int idx) {
	if (idx < 0 || idx >= MAXSLOTS || !this->_inventory[idx])
		return ;
	this->storeMateria(*this->_inventory[idx]);
	this->_inventory[idx] = nullptr;
}

void	Character::use(int idx, ICharacter & target) {
	if (idx < 0 || idx >= MAXSLOTS || !this->_inventory[idx])
		return ;
	this->_inventory[idx]->use(target);
}
