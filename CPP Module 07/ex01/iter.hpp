/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 16:55:46 by hel-makh          #+#    #+#             */
/*   Updated: 2022/05/29 14:29:49 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

template <typename T>
void	iter(T * arr, int size, void (&func)(T const &)) {
	for (int i = 0; i < size; i ++) {
		func(arr[i]);
	}
}

#endif