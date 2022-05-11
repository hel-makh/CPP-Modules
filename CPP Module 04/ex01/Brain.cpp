/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:39:02 by hel-makh          #+#    #+#             */
/*   Updated: 2022/05/10 17:50:34 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

/*************************[ Constructors/Destructors ]*************************/

Brain::Brain(void) {
	std::cout << "Brain Default constructor called." << std::endl;
	return ;
}

Brain::Brain(std::string const ideas[100]) {
	std::cout << "Brain Ideas constructor called." << std::endl;
	this->setIdeas(ideas);
	return ;
}

Brain::Brain(Brain const & rhs) {
	std::cout << "Brain Copy constructor called." << std::endl;
	*this = rhs;
}

Brain::~Brain(void) {
	std::cout << "Brain Destructor called." << std::endl;
}

/****************************[ Operators overload ]****************************/

Brain &	Brain::operator=(Brain const & rhs) {
	std::cout << "Brain Copy assignment operator called." << std::endl;
	this->setIdeas(rhs.getIdeas());
	return (*this);
}

/*****************************[ Member Functions ]*****************************/

std::string *	Brain::getIdeas(void) const {
	return ((std::string *)this->_ideas);
}

void	Brain::setIdeas(std::string const ideas[100]) {
	for (int i = 0; i < 100; i ++)
		this->_ideas[i] = ideas[i];
}
