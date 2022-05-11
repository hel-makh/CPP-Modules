/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 18:15:55 by hel-makh          #+#    #+#             */
/*   Updated: 2022/05/11 10:23:23 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_H
# define BRAIN_H

# include <iostream>
# include <string>

class Brain	{
	private:
		std::string	_ideas[100];

	public:
		Brain(void);
		Brain(std::string const ideas[100]);
		Brain(Brain const & rhs);
		~Brain(void);

		Brain &	operator=(Brain const & rhs);

		std::string *	getIdeas(void) const;
		void			setIdeas(std::string const ideas[100]);
};

#endif