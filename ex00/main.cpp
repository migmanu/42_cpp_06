/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:51:25 by jmigoya-          #+#    #+#             */
/*   Updated: 2024/05/08 16:17:30 by jmigoya-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <ostream>

int	main(int argc, char *argv[])
{
	if (argc != 2 || !argv[1][0])
	{
		std::cout << "Wrong input. Use: ./exec <literal>" << std::endl;
	}
	ScalarConverter::convert(argv[1]);
	return 0;
}
