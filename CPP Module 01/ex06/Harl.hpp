/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 23:37:04 by hel-makh          #+#    #+#             */
/*   Updated: 2022/04/24 17:08:26 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_H
# define HARL_H

# include <iostream>
# include <string>

class Harl {
	public:
		Harl(void);
		~Harl(void);
		void			complain(std::string level);
	private:
		typedef struct s_levels {
			std::string	level;
		}	t_levels;
		
		t_levels		*levels;

		void			debug(void);
		void			info(void);
		void			warning(void);
		void			error(void);
		void			notfound(void);
};

#endif