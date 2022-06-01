/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:20:04 by hel-makh          #+#    #+#             */
/*   Updated: 2022/06/01 14:10:35 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP

# include <iostream>
# include <string>
# include <fstream>
# include <iomanip>

# include "Form.hpp"

class ShrubberyCreationForm : public Form {
	private:
		std::string const	_target;

		void	execution(void) const;
	
	public:
		ShrubberyCreationForm(std::string const target = "");
		ShrubberyCreationForm(ShrubberyCreationForm const & rhs);
		~ShrubberyCreationForm(void) {}

		ShrubberyCreationForm &	operator=(ShrubberyCreationForm const & rhs);
		
		std::string const &	getTarget(void) const;
};

std::ostream &  operator<<(std::ostream & o, ShrubberyCreationForm const & rhs);

#endif