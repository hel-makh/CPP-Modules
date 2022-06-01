/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:20:04 by hel-makh          #+#    #+#             */
/*   Updated: 2022/06/01 14:05:35 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <exception>

# include "Bureaucrat.hpp"

# define HIGHEST_GRADE	1
# define LOWEST_GRADE	150

class Form {
	private:
		std::string const	_name;
		bool				_signed;
		int const			_to_sign;
		int const			_to_exec;

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

		class NotSignedException : public std::exception {
			char const *	what() const throw() {
				return "Form not signed.";
			}
		};

	protected:
		virtual void	execution(void) const = 0;
	
	public:
		Form(void);
		Form(std::string const name, int to_sign = 1, int to_exec = 1);
		Form(Form const & rhs);
		virtual	~Form(void) {}
		
		std::string const &	getName(void) const;
		bool				isSigned(void) const;
		int					toSign(void) const;
		int					toExec(void) const;

		void	beSigned(Bureaucrat const & b);
		void	execute(Bureaucrat const & executor) const;
};

std::ostream &  operator<<(std::ostream & o, Form const & rhs);

#endif