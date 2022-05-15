/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 16:01:26 by hel-makh          #+#    #+#             */
/*   Updated: 2022/05/15 14:40:17 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

/*************************[ Constructors/Destructors ]*************************/

Ice::Ice(void) {
	this->_type = "ice";
}

Ice::Ice(Ice const & rhs) {
	*this = rhs;
}

/****************************[ Operators overload ]****************************/

Ice &	Ice::operator=(Ice const & rhs) {
	(void) rhs;
	return (*this);
}

/*****************************[ Member Functions ]*****************************/

AMateria *	Ice::clone(void) const {
	AMateria *	newMateria;

	newMateria = new Ice();
	return (newMateria);
}

void	Ice::use(ICharacter & target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
