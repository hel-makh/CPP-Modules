/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 16:41:59 by hel-makh          #+#    #+#             */
/*   Updated: 2022/05/15 14:40:19 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

/*************************[ Constructors/Destructors ]*************************/

Cure::Cure(void) {
	this->_type = "cure";
}

Cure::Cure(Cure const & rhs) {
	*this = rhs;
}

/****************************[ Operators overload ]****************************/

Cure &	Cure::operator=(Cure const & rhs) {
	(void) rhs;
	return (*this);
}

/*****************************[ Member Functions ]*****************************/

AMateria *	Cure::clone(void) const {
	AMateria *	newMateria;

	newMateria = new Cure();
	return (newMateria);
}

void	Cure::use(ICharacter & target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
