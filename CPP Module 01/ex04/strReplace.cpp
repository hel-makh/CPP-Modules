/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strReplace.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 18:31:05 by hel-makh          #+#    #+#             */
/*   Updated: 2022/05/10 14:49:20 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strReplace.hpp"

void	strReplace(std::string& str, char* s1, char* s2) {
	size_t	occurrence;

	if (!s1 || !s1[0])
		return ;
	occurrence = 0;
	while ((occurrence = str.find(s1, occurrence)) != std::string::npos)
	{
		str.erase(occurrence, strlen(s1));
		str.insert(occurrence, s2);
		occurrence += strlen(s2);
	}
}
