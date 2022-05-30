/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 10:37:59 by hel-makh          #+#    #+#             */
/*   Updated: 2022/05/30 18:05:20 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <algorithm>
# include <vector>
# include <functional>

class Span {
	private:
		std::size_t			_N;
		std::vector<int>	_vec;

		class CannotAddNumber: public std::exception {
			public:
				char const *	what(void) const throw() {
					return ("Couldn't add number, span is full.");
				}
		};

		class CannotBulkAddNumber: public std::exception {
			public:
				char const *	what(void) const throw() {
					return ("Couldn't bulk add numbers, no enough space.");
				}
		};
	
	public:	
		Span(std::size_t N);
		Span(Span const & rhs);
		~Span(void) {}

		Span &	operator=(Span const & rhs);

		std::size_t					getSize(void) const;
		std::vector<int> const &	getVector(void) const;

		void	addNumber(int n);
		int		shortestSpan(void) const;
		int		longestSpan(void) const;

		void	bulkAdd(std::vector<int>::iterator begin,
						std::vector<int>::iterator end);
};

#endif