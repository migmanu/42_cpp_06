/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 16:50:47 by jmigoya-          #+#    #+#             */
/*   Updated: 2024/05/30 20:04:36 by jmigoya-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serializer.hpp"
#include <iostream>
#include <stdint.h>

int main(void)
{
	Data *d1 = new Data();
	d1->type = "Hola, mundo!";
	d1->value = 42;
	uintptr_t serialized = Serializer::serialize(d1);
	std::cout << "serialized is: " << serialized << std::endl;
	Data *d2 = Serializer::deserialize(serialized);
	std::cout << "d2 is type: " << d2->type << "with value:" << d2->value
			  << std::endl;
	delete d1;
	return 0;
}
