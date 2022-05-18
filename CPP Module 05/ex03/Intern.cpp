/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:17:50 by hel-makh          #+#    #+#             */
/*   Updated: 2022/05/18 17:30:24 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

/*****************************[ Member Functions ]*****************************/

Form *	Intern::makeSForm(std::string const target) {
	return (new ShrubberyCreationForm(target));
}

Form *	Intern::makeRForm(std::string const target) {
	return (new RobotomyRequestForm(target));
}

Form *	Intern::makePForm(std::string const target) {
	return (new PresidentialPardonForm(target));
}

Form *	Intern::makeForm(std::string const name, std::string const target) {
	Form *	(Intern::*newForm[3])(std::string const);

	newForm[0] = &Intern::makeSForm;
	newForm[1] = &Intern::makeRForm;
	newForm[2] = &Intern::makePForm;

	for (int i = 0; i < 3; i ++) {
		Form * form = (this->*newForm[i])(target);
		if (form->getName() == name) {
			std::cout << "Intern creates " << name << std::endl;
			return (form);
		}
		delete form;
	}
	
	std::cerr << "Intern couldn't find " << name << std::endl;
	return (nullptr);
}
