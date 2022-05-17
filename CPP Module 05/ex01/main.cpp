/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 15:13:45 by hel-makh          #+#    #+#             */
/*   Updated: 2022/05/17 13:41:02 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void) {
	Bureaucrat	b("Bureaucrat 1", 20);
	Form		f("Form 1", 10);
	Form		f2("Form 2", 15);

	std::cout << b << std::endl;
	std::cout << f;
	std::cout << f2;

	b.incrementGrade(5);

	b.signForm(f);
	b.signForm(f2);
	
	std::cout << b << std::endl;
	std::cout << f;
	std::cout << f2;

	return (0);
}
