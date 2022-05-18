/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 17:53:18 by hel-makh          #+#    #+#             */
/*   Updated: 2022/05/17 16:39:42 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

/*************************[ Constructors/Destructors ]*************************/

RobotomyRequestForm::RobotomyRequestForm(
	std::string const target
	) :	_name("Robotomy Request"),
		_target(target),
		_to_sign(72),
		_to_exec(45) {
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(
	RobotomyRequestForm const & rhs
	) :	_name(rhs.getName()),
		_target(rhs.getTarget()),
		_to_sign(rhs.toSign()),
		_to_exec(rhs.toExec()) {
	return ;
}

/****************************[ Operators overload ]****************************/

RobotomyRequestForm &	RobotomyRequestForm::operator=(
	RobotomyRequestForm const & rhs
	) {
	if (this != &rhs) {
		this->~RobotomyRequestForm();
		new (this) RobotomyRequestForm(rhs);
	}
	return (*this);
}

std::ostream &	operator<<(std::ostream & o, RobotomyRequestForm const & rhs) {
	o << "Form name: " << rhs.getName() << std::endl;
	o << "Signed: " << (rhs.isSigned() ? "yes" : "no") << std::endl;
	o << "Grade required to sign: " << rhs.toSign() << std::endl;
	o << "Grade required to execute: " << rhs.toExec() << std::endl;
	return (o);
}

/*****************************[ Member Functions ]*****************************/

std::string const &	RobotomyRequestForm::getName(void) const {
	return (this->_name);
}

std::string const &	RobotomyRequestForm::getTarget(void) const {
	return (this->_target);
}

int	RobotomyRequestForm::toSign(void) const {
	return (this->_to_sign);
}

int	RobotomyRequestForm::toExec(void) const {
	return (this->_to_exec);
}

void	RobotomyRequestForm::execution(void) const {
	srand(time(NULL));
	switch (rand() % 2 + 1) {
		case 1:
			std::cout << this->getName() << " has been robotomized successfully." << std::endl;
			break ;
		case 2:
			std::cout << "The robotomy failed." << std::endl;
			break ;
	}
}
