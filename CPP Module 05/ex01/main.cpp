/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 15:13:45 by hel-makh          #+#    #+#             */
/*   Updated: 2022/06/01 14:26:54 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void) {
	try { 
		Bureaucrat	b("Bureaucrat 1", 20);
		Form		f("Form 1", 150);
		Form		f2("Form 2", 140);

		b.incrementGrade(5);

		std::cout << b << std::endl << std::endl;
		std::cout << f << std::endl;
		std::cout << f2 << std::endl;

		b.signForm(f);
		b.signForm(f2);
		
		std::cout << b << std::endl << std::endl;
		std::cout << f << std::endl;
		std::cout << f2 << std::endl;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	return (0);
}
