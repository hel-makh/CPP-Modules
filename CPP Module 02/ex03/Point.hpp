/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 16:52:15 by hel-makh          #+#    #+#             */
/*   Updated: 2022/05/07 17:16:42 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
# define POINT_H

# include "Fixed.hpp"

class Point	{
	public:
		Point(void);
		Point(float const x, float const y);
		Point(Point const & rhs);
		~Point(void);

		Point &	operator=(Point const & rhs);

		Fixed	getX(void) const;
		Fixed	getY(void) const;
	private:
		Fixed const	_x;
		Fixed const	_y;
};

#endif