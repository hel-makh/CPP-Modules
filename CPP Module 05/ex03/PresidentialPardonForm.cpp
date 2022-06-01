/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 17:53:18 by hel-makh          #+#    #+#             */
/*   Updated: 2022/05/17 16:39:42 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/*************************[ Constructors/Destructors ]*************************/

PresidentialPardonForm::PresidentialPardonForm(
	std::string const target
	) :	Form("Presidential Pardon", 25, 5),
		_target(target) {
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(
	PresidentialPardonForm const & rhs
	) :	Form(rhs.getName(), rhs.toSign(), rhs.toExec()),
		_target(rhs.getTarget()) {
	return ;
}

/****************************[ Operators overload ]****************************/

PresidentialPardonForm &	PresidentialPardonForm::operator=(
	PresidentialPardonForm const & rhs
	) {
	if (this != &rhs) {
		this->~PresidentialPardonForm();
		new (this) PresidentialPardonForm(rhs);
	}
	return (*this);
}

std::ostream &	operator<<(std::ostream & o, PresidentialPardonForm const & rhs) {
	o << "Form name: " << rhs.getName() << std::endl;
	o << "Signed: " << (rhs.isSigned() ? "yes" : "no") << std::endl;
	o << "Grade required to sign: " << rhs.toSign() << std::endl;
	o << "Grade required to execute: " << rhs.toExec() << std::endl;
	return (o);
}

/*****************************[ Member Functions ]*****************************/

std::string const &	PresidentialPardonForm::getTarget(void) const {
	return (this->_target);
}

void	PresidentialPardonForm::execution(void) const {
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
