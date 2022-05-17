/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:44:48 by hel-makh          #+#    #+#             */
/*   Updated: 2022/05/17 13:06:59 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
# include "Form.hpp"

/*************************[ Constructors/Destructors ]*************************/

Bureaucrat::Bureaucrat(std::string const name, int grade) :	_name(name),
															_grade(grade) {
	try {
		if (grade < HIGHEST_GRADE)
			throw GradeTooHighException();
		else if (grade > LOWEST_GRADE)
			throw GradeTooLowException();
	} catch(std::exception & e) {
		std::cout << this->getName() << ", " << e.what() << std::endl;
	}
}

Bureaucrat::Bureaucrat(Bureaucrat const & rhs) {
	new (this) Bureaucrat(rhs.getName(), rhs.getGrade());
}

/****************************[ Operators overload ]****************************/

Bureaucrat &	Bureaucrat::operator=(Bureaucrat const & rhs) {
	if (this != &rhs) {
		this->~Bureaucrat();
		new (this) Bureaucrat(rhs);
	}
	return (*this);
}

std::ostream &	operator<<(std::ostream & o, Bureaucrat const & rhs) {
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
	return (o);
}

/*****************************[ Member Functions ]*****************************/

std::string const &	Bureaucrat::getName(void) const {
	return (this->_name);
}

int	Bureaucrat::getGrade(void) const {
	return (this->_grade);
}

void	Bureaucrat::incrementGrade(int amount) {
	try {
		if (this->getGrade() - amount < HIGHEST_GRADE)
			throw GradeTooHighException();
		this->_grade -= amount;
	} catch(std::exception & e) {
		std::cout << e.what() << std::endl;
	}
}

void	Bureaucrat::decrementGrade(int amount) {
	try {
		if (this->getGrade() + amount > LOWEST_GRADE)
			throw GradeTooLowException();
		this->_grade += amount;
	} catch(std::exception & e) {
		std::cout << e.what() << std::endl;
	}
}

void	Bureaucrat::signForm(Form & f) {
	try {
		f.beSigned(*this);
		std::cout << this->getName() << " signed " << f.getName() << std::endl;
	} catch (std::exception & e) {
		std::cout << this->getName() << " couldn't sign " << f.getName() << ", " << e.what() << std::endl;
	}
}
