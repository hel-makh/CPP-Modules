/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 17:29:24 by hel-makh          #+#    #+#             */
/*   Updated: 2022/05/28 19:16:21 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <stdexcept>

template <typename T>
class Array {
	private:
		T				*_arr;
		unsigned int	_size;
	
	public:
		Array(void);
		Array(unsigned int size);
		Array(Array<T> const & rhs);
		~Array(void);

		Array<T> &	operator=(Array<T> const & rhs);
		T &			operator[](unsigned int index) const;

		unsigned int	size(void) const;
};

#endif