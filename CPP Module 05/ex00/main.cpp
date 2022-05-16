/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 15:13:45 by hel-makh          #+#    #+#             */
/*   Updated: 2022/05/16 15:20:57 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void) {
	Bureaucrat	b("b1", 15);
	Bureaucrat	b2("b2", 151);
	Bureaucrat	b3("b3", -100);

	std::cout << b << std::endl;
	std::cout << b2 << std::endl;
	std::cout << b3 << std::endl;

	return (0);
}
