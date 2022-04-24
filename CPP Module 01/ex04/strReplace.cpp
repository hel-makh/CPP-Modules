/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strReplace.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 18:31:05 by hel-makh          #+#    #+#             */
/*   Updated: 2022/04/24 18:31:19 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strReplace.hpp"

void	strReplace(std::string& str, char* s1, char* s2) {
	size_t	s1_pos;

	s1_pos = str.find(s1);
	if (s1_pos == std::string::npos)
		return ;
	str.erase(s1_pos, strlen(s1));
	str.insert(s1_pos, s2);
}
