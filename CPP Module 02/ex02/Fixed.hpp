/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 14:18:33 by hel-makh          #+#    #+#             */
/*   Updated: 2022/05/07 16:21:22 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

# include <iostream>
# include <cmath>

class Fixed {
	public:
		Fixed(void);
		Fixed(int const number);
		Fixed(float const number);
		Fixed(Fixed const & src);
		~Fixed(void);
		
		Fixed &	operator=(Fixed const & rhs);

		bool	operator>(Fixed const & rhs) const;
		bool	operator<(Fixed const & rhs) const;
		bool	operator>=(Fixed const & rhs) const;
		bool	operator<=(Fixed const & rhs) const;
		bool	operator==(Fixed const & rhs) const;
		bool	operator!=(Fixed const & rhs) const;

		Fixed	operator+(Fixed const & rhs) const;
		Fixed	operator-(Fixed const & rhs) const;
		Fixed	operator*(Fixed const & rhs) const;
		Fixed	operator/(Fixed const & rhs) const;

		Fixed	operator++(void);
		Fixed	operator++(int);
		Fixed	operator--(void);
		Fixed	operator--(int);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		int		toInt(void) const;
		float	toFloat(void) const;

		static Fixed &	min(Fixed & fixed1, Fixed & fixed2);
		static Fixed const &	min(Fixed const & fixed1, Fixed const & fixed2);
		static Fixed &	max(Fixed & fixed1, Fixed & fixed2);
		static Fixed const &	max(Fixed const & fixed1, Fixed const & fixed2);
	private:
		int					value;
		static const int	fractionalBits = 8;
};

std::ostream &  operator<<(std::ostream & o, Fixed const & rhs);

#endif