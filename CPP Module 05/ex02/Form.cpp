/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 17:53:18 by hel-makh          #+#    #+#             */
/*   Updated: 2022/06/01 14:25:09 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/*************************[ Constructors/Destructors ]*************************/

Form::Form(void) :	_name(""),
					_to_sign(0),
					_to_exec(0) {
	return ;
}

Form::Form(
	std::string const name, int to_sign, int to_exec
	) :	_name(name),
		_signed(false),
		_to_sign(to_sign),
		_to_exec(to_exec) {
	if (to_sign < HIGHEST_GRADE || to_exec < HIGHEST_GRADE)
		throw GradeTooHighException();
	else if (to_sign > LOWEST_GRADE || to_exec > LOWEST_GRADE)
		throw GradeTooLowException();
}

Form::Form(Form const & rhs) :	_name(rhs.getName()),
								_signed(false),
								_to_sign(rhs.toSign()),
								_to_exec(rhs.toExec()) {
	return ;
}

/****************************[ Operators overload ]****************************/

std::ostream &	operator<<(std::ostream & o, Form const & rhs) {
	o << "Form name: " << rhs.getName() << std::endl;
	o << "Signed: " << (rhs.isSigned() ? "yes" : "no") << std::endl;
	o << "Grade required to sign: " << rhs.toSign() << std::endl;
	o << "Grade required to execute: " << rhs.toExec() << std::endl;
	return (o);
}

/*****************************[ Member Functions ]*****************************/

std::string const &	Form::getName(void) const {
	return (this->_name);
}

bool	Form::isSigned(void) const {
	return (this->_signed);
}

int	Form::toSign(void) const {
	return (this->_to_sign);
}

int	Form::toExec(void) const {
	return (this->_to_exec);
}

void	Form::beSigned(Bureaucrat const & b) {
	if (b.getGrade() > this->toSign())
		throw GradeTooLowException();
	this->_signed = true;
}

void	Form::execute(Bureaucrat const & executor) const {
	if (!this->isSigned())
		throw NotSignedException();
	if (executor.getGrade() > this->toExec())
		throw GradeTooLowException();
	execution();
}
