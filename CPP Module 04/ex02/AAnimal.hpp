/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:19:54 by hel-makh          #+#    #+#             */
/*   Updated: 2022/05/12 13:32:59 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
# define ANIMAL_H

# include <iostream>
# include <string>

class AAnimal {
	protected:
		std::string	_type;
	
	public:
		AAnimal(void);
		AAnimal(std::string const type);
		AAnimal(AAnimal const & rhs);
		virtual	~AAnimal(void);

		AAnimal &	operator=(AAnimal const & rhs);

		std::string	getType(void) const;
		void		setType(std::string const type);
		
		virtual void	makeSound(void) const = 0;
};

#endif