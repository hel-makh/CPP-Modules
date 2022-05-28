/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 16:55:46 by hel-makh          #+#    #+#             */
/*   Updated: 2022/05/28 17:05:43 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

template <typename T>
void	funcIter(T * arr, int size, void (&func)(T&)) {
	for (int i = 0; i < size; i ++) {
		func(arr[i]);
	}
}

#endif