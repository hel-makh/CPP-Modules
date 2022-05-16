/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:36:15 by hel-makh          #+#    #+#             */
/*   Updated: 2022/05/16 19:00:23 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

// # include "Form.hpp"

# define HIGHEST_GRADE	0
# define LOWEST_GRADE	150

// class Form;

class Bureaucrat {
	private:
		std::string const	_name;
		int					_grade;

		class GradeTooHighException : public std::exception {
			char const *	what() const throw() {
				return "Grade too high.";
			}
		};

		class GradeTooLowException : public std::exception {
			char const *	what() const throw() {
				return "Grade too low.";
			}
		};
	
	public:
		Bureaucrat(std::string const name, int grade);
		Bureaucrat(Bureaucrat const & rhs);
		~Bureaucrat(void) {}

		Bureaucrat &	operator=(Bureaucrat const & rhs);
		
		std::string const &	getName(void) const;
		int					getGrade(void) const;

		void	incrementGrade(int amount);
		void	decrementGrade(int amount);
		// void	signForm(Form const & f);
};

std::ostream &  operator<<(std::ostream & o, Bureaucrat const & rhs);

#endif