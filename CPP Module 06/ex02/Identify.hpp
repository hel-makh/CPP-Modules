/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identify.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 15:44:15 by hel-makh          #+#    #+#             */
/*   Updated: 2022/05/24 16:12:30 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IDENTIFY_HPP
# define IDENTIFY_HPP

# include <iostream>
# include <string>
# include <stdlib.h>
# include <time.h>

# include "Classes.hpp"

Base *	generate(void);
void	identify(Base * p);
void	identify(Base & p);

#endif