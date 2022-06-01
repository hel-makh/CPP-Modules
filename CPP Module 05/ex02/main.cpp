/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 15:13:45 by hel-makh          #+#    #+#             */
/*   Updated: 2022/06/01 14:25:22 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void) {
	try {
		Bureaucrat				b("Bureaucrat", 30);
		ShrubberyCreationForm	sF("Home");
		RobotomyRequestForm		rF("Robot");
		PresidentialPardonForm	pF("President");

		std::cout << b << std::endl;
		std::cout << sF;
		std::cout << rF;
		std::cout << pF << std::endl;

		b.signForm(sF);
		b.signForm(rF);
		b.signForm(pF);

		b.executeForm(sF);
		b.executeForm(rF);
		b.executeForm(pF);
		
		std::cout << std::endl << b << std::endl;
		std::cout << sF;
		std::cout << rF;
		std::cout << pF;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	return (0);
}
