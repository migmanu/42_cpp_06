/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 16:45:04 by jmigoya-          #+#    #+#             */
/*   Updated: 2024/05/10 16:50:03 by jmigoya-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data(void) : type("Data type"), value(1)
{
	return;
}

Data::Data(const Data &src) : type(src.type), value(src.value)
{
	return;
}

Data::~Data(void)
{
	return;
}

Data &Data::operator=(const Data &rhs)
{
	if (this == &rhs)
		return (*this);
	this->type = rhs.type;
	this->value = rhs.value;
	return *this;
}
