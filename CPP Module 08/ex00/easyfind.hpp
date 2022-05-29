/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 15:06:08 by hel-makh          #+#    #+#             */
/*   Updated: 2022/05/29 16:38:54 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>

class notFound : public std::exception {
	public:
		char const *	what(void) const throw() {
			return ("Element not found");
		}
};

template <typename T>
typename T::iterator	easyfind(T & container, int element) {
	typename T::iterator	it;

	it = find(container.begin(), container.end(), element);
	if (it == container.end())
		throw notFound();
	return (it);
}

#endif