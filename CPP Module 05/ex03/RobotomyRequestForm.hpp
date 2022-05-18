/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:20:04 by hel-makh          #+#    #+#             */
/*   Updated: 2022/05/18 10:59:35 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTMY_REQUEST_FORM_HPP
# define ROBOTMY_REQUEST_FORM_HPP

# include <iostream>
# include <string>
# include <stdlib.h>
# include <time.h>

# include "Form.hpp"

class RobotomyRequestForm : public Form {
	private:
		std::string const	_name;
		std::string const	_target;
		int const			_to_sign;
		int const			_to_exec;

		void	execution(void) const;
	
	public:
		RobotomyRequestForm(std::string const target = "");
		RobotomyRequestForm(RobotomyRequestForm const & rhs);
		~RobotomyRequestForm(void) {}

		RobotomyRequestForm &	operator=(RobotomyRequestForm const & rhs);
		
		std::string const &	getName(void) const;
		std::string const &	getTarget(void) const;
		int					toSign(void) const;
		int					toExec(void) const;
};

std::ostream &  operator<<(std::ostream & o, RobotomyRequestForm const & rhs);

#endif