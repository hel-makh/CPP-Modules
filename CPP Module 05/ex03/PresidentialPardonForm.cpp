/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 17:53:18 by hel-makh          #+#    #+#             */
/*   Updated: 2022/05/18 17:26:56 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/*************************[ Constructors/Destructors ]*************************/

PresidentialPardonForm::PresidentialPardonForm(
	std::string const target
	) :	_name("Presidential Pardon"),
		_target(target),
		_to_sign(25),
		_to_exec(5) {
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(
	PresidentialPardonForm const & rhs
	) :	_name(rhs.getName()),
		_target(rhs.getTarget()),
		_to_sign(rhs.toSign()),
		_to_exec(rhs.toExec()) {
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

std::string const &	PresidentialPardonForm::getName(void) const {
	return (this->_name);
}

std::string const &	PresidentialPardonForm::getTarget(void) const {
	return (this->_target);
}

int	PresidentialPardonForm::toSign(void) const {
	return (this->_to_sign);
}

int	PresidentialPardonForm::toExec(void) const {
	return (this->_to_exec);
}

void	PresidentialPardonForm::execution(void) const {
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
