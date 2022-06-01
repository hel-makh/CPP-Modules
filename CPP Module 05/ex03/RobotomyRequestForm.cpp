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
	) :	Form("Robotomy Request", 72, 45),
		_target(target) {
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(
	RobotomyRequestForm const & rhs
	) :	Form(rhs.getName(), rhs.toSign(), rhs.toExec()),
		_target(rhs.getTarget()) {
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

std::string const &	RobotomyRequestForm::getTarget(void) const {
	return (this->_target);
}

void	RobotomyRequestForm::execution(void) const {
	srand(time(NULL));
	switch (rand() % 2 + 1) {
		case 1:
			std::cout << this->getTarget() << " has been robotomized successfully." << std::endl;
			break ;
		case 2:
			std::cout << "The robotomy failed." << std::endl;
			break ;
	}
}
