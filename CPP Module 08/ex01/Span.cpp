/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 10:42:36 by hel-makh          #+#    #+#             */
/*   Updated: 2022/05/31 10:22:01 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/*************************[ Constructors/Destructors ]*************************/

Span::Span(std::size_t N) : _N(N) {
	return ;
}

Span::Span(Span const & rhs) {
	new (this) Span(rhs.getSize());
	this->_vec.assign(rhs.getVector().begin(), rhs.getVector().end());
}

/****************************[ Operators overload ]****************************/

Span &	Span::operator=(Span const & rhs) {
	if (this != &rhs) {
		this->~Span();
		new (this) Span(rhs);
	}
	return (*this);
}

/*****************************[ Member Functions ]*****************************/

std::size_t	Span::getSize(void) const {
	return (this->_N);
}

std::vector<int> const &	Span::getVector(void) const {
	return (this->_vec);
}

void	Span::addNumber(int n) {
	if (this->_vec.size() >= this->_N)
		throw CannotAddNumber();
	this->_vec.push_back(n);
}

int	Span::shortestSpan(void) const {
	std::vector<int>	vec;
	int					shortestSpan;

	vec.assign(this->_vec.begin(), this->_vec.end());
	std::sort(vec.begin(), vec.end());
	if (vec.size() < 2)
		return (0);
	shortestSpan = vec[1] - vec[0];
	for (std::size_t i = 0; i < vec.size() - 1; i ++) {
		if (shortestSpan > vec[i + 1] - vec[i])
			shortestSpan = vec[i + 1] - vec[i];
	}
	return (shortestSpan);
}

int	Span::longestSpan(void) const {
	int	min = *std::min_element(this->_vec.begin(), this->_vec.end());
	int	max = *std::max_element(this->_vec.begin(), this->_vec.end());
	return (max - min);
}
