/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 17:53:18 by hel-makh          #+#    #+#             */
/*   Updated: 2022/05/17 18:42:41 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

/*************************[ Constructors/Destructors ]*************************/

ShrubberyCreationForm::ShrubberyCreationForm(
	std::string const name
	) :	_name(name),
		_to_sign(145),
		_to_exec(137) {
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(
	ShrubberyCreationForm const & rhs
	) :	_name(rhs.getName()),
		_to_sign(rhs.toSign()),
		_to_exec(rhs.toExec()) {
	return ;
}

/****************************[ Operators overload ]****************************/

ShrubberyCreationForm &	ShrubberyCreationForm::operator=(
	ShrubberyCreationForm const & rhs
	) {
	if (this != &rhs) {
		this->~ShrubberyCreationForm();
		new (this) ShrubberyCreationForm(rhs);
	}
	return (*this);
}

std::ostream &	operator<<(std::ostream & o, ShrubberyCreationForm const & rhs) {
	o << "Form name: " << rhs.getName() << std::endl;
	o << "Signed: " << (rhs.isSigned() ? "yes" : "no") << std::endl;
	o << "Grade required to sign: " << rhs.toSign() << std::endl;
	o << "Grade required to execute: " << rhs.toExec() << std::endl;
	return (o);
}

/*****************************[ Member Functions ]*****************************/

std::string const &	ShrubberyCreationForm::getName(void) const {
	return (this->_name);
}

int	ShrubberyCreationForm::toSign(void) const {
	return (this->_to_sign);
}

int	ShrubberyCreationForm::toExec(void) const {
	return (this->_to_exec);
}

void	ShrubberyCreationForm::execution(void) const {
	std::ofstream	file;

	file.open(this->getName() + "_shrubbery");
	if (!file.is_open())
		std::cerr << "Error: Couldn't open <" << this->getName() << "_shrubbery> file." << std::endl;
	file.close();
}
