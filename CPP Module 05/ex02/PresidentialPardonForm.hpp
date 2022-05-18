/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:20:04 by hel-makh          #+#    #+#             */
/*   Updated: 2022/05/17 16:51:24 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIAL_PARDON_FORM_HPP
# define PRESIDENTIAL_PARDON_FORM_HPP

# include <iostream>
# include <string>

# include "Form.hpp"

class PresidentialPardonForm : public Form {
	private:
		std::string const	_name;
		std::string const	_target;
		int const			_to_sign;
		int const			_to_exec;

		void	execution(void) const;
	
	public:
		PresidentialPardonForm(std::string const target = "");
		PresidentialPardonForm(PresidentialPardonForm const & rhs);
		~PresidentialPardonForm(void) {}

		PresidentialPardonForm &	operator=(PresidentialPardonForm const & rhs);
		
		std::string const &	getName(void) const;
		std::string const &	getTarget(void) const;
		int					toSign(void) const;
		int					toExec(void) const;
};

std::ostream &  operator<<(std::ostream & o, PresidentialPardonForm const & rhs);

#endif