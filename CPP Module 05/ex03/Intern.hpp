/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:17:20 by hel-makh          #+#    #+#             */
/*   Updated: 2022/05/18 16:42:20 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>

# include "Form.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern {
	private:
		Form *	makeSForm(std::string const target);
		Form *	makeRForm(std::string const target);
		Form *	makePForm(std::string const target);
	
	public:
		Intern(void) {}
		~Intern(void) {}

		Form *	makeForm(std::string const name, std::string const target);
};

#endif