/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 17:03:46 by hel-makh          #+#    #+#             */
/*   Updated: 2022/05/06 18:17:09 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

# include <iostream>

class Fixed {
	public:
		Fixed(void);
		Fixed(Fixed const & src);
		~Fixed(void);
		
		Fixed &	operator=(Fixed const & copy);
		
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
	private:
		int					value;
		static const int	fractionalBits = 8;
};

#endif