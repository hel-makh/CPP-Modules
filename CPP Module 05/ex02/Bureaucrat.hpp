/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:36:15 by hel-makh          #+#    #+#             */
/*   Updated: 2022/05/24 14:46:58 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

# define HIGHEST_GRADE	1
# define LOWEST_GRADE	150

class Form;

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
		Bureaucrat(std::string const name, int grade = 1);
		Bureaucrat(Bureaucrat const & rhs);
		~Bureaucrat(void) {}

		Bureaucrat &	operator=(Bureaucrat const & rhs);
		
		std::string const &	getName(void) const;
		int					getGrade(void) const;

		void	incrementGrade(int amount);
		void	decrementGrade(int amount);
		void	signForm(Form & f);
		void	executeForm(Form const & f);
};

std::ostream &  operator<<(std::ostream & o, Bureaucrat const & rhs);

#endif