/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 17:53:18 by hel-makh          #+#    #+#             */
/*   Updated: 2022/06/01 14:10:32 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

/*************************[ Constructors/Destructors ]*************************/

ShrubberyCreationForm::ShrubberyCreationForm(
	std::string const target
	) :	Form("Shrubbery Creation", 145, 137),
		_target(target) {
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(
	ShrubberyCreationForm const & rhs
	) :	Form(rhs.getName(), rhs.toSign(), rhs.toExec()),
		_target(rhs.getTarget()) {
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
	o << "Form target: " << rhs.getTarget() << std::endl;
	o << "Signed: " << (rhs.isSigned() ? "yes" : "no") << std::endl;
	o << "Grade required to sign: " << rhs.toSign() << std::endl;
	o << "Grade required to execute: " << rhs.toExec() << std::endl;
	return (o);
}

/*****************************[ Member Functions ]*****************************/

std::string const &	ShrubberyCreationForm::getTarget(void) const {
	return (this->_target);
}

void	ShrubberyCreationForm::execution(void) const {
	std::ofstream	file;

	file.open(this->getTarget() + "_shrubbery");
	if (!file.is_open())
		std::cerr << "Error: Couldn't open <" << this->getTarget() << "_shrubbery> file." << std::endl;
	
	int	treeHeight = 50;
	for (int i = 0; i < treeHeight; i ++) {
		std::string	str = "";
		for (int j = 0; j < i; j ++) {
			str += "#";
		}
		file << std::setw(treeHeight) << str;
		file << "#" << str << std::endl;
	}
	for (int i = 0; i < 5; i ++) {
		file << std::setw(treeHeight) << "###" << std::endl;
	}

	file.close();
}
