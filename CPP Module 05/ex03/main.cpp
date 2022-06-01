/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 15:13:45 by hel-makh          #+#    #+#             */
/*   Updated: 2022/06/01 14:21:35 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"

int	main(void) {
	try {
		Bureaucrat	b("Bureaucrat", 30);
		Intern		someRandomIntern;

		Form *	rrf;
		
		rrf = someRandomIntern.makeForm("Robotomy Request", "Bender");
		if (rrf) {
			b.signForm(*rrf);
			b.executeForm(*rrf);
		}

		Form *	rrf2;
		rrf2 = someRandomIntern.makeForm("Unknown", "Bender");

		delete rrf;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	return (0);
}
