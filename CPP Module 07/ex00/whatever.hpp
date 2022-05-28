/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 16:41:16 by hel-makh          #+#    #+#             */
/*   Updated: 2022/05/28 16:45:57 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
void	swap(T & v1, T & v2) {
	T	temp;

	temp = v1;
	v1 = v2;
	v2 = temp;
}

template <typename T>
T const & min(T const & v1, T const & v2) {
	return (v1 <= v2 ? v1 : v2);
}

template <typename T>
T const & max(T const & v1, T const & v2) {
	return (v1 >= v2 ? v1 : v2);
}

#endif