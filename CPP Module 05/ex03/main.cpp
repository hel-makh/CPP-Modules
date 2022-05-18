/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 15:13:45 by hel-makh          #+#    #+#             */
/*   Updated: 2022/05/18 18:27:51 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"

int	main(void) {
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

	return (0);
}
