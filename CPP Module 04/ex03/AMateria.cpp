/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 12:51:56 by hel-makh          #+#    #+#             */
/*   Updated: 2022/05/15 14:40:12 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

/*************************[ Constructors/Destructors ]*************************/

AMateria::AMateria(void) {
	return ;
}

AMateria::AMateria(std::string const & type) : _type(type) {
	return ;
}

AMateria::AMateria(AMateria const & rhs) {
	*this = rhs;
}

/****************************[ Operators overload ]****************************/

AMateria &	AMateria::operator=(AMateria const & rhs) {
	(void) rhs;
	return (*this);
}

/*****************************[ Member Functions ]*****************************/

std::string const &	AMateria::getType(void) const {
	return (this->_type);
}

void	AMateria::setType(std::string const & type) {
	this->_type = type;
}

void	AMateria::use(ICharacter & target) {
	(void)target;
	return ;
}
