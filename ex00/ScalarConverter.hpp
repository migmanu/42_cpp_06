/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:51:36 by jmigoya-          #+#    #+#             */
/*   Updated: 2024/05/08 16:47:11 by jmigoya-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

enum e_type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	TOO_LARGE,
	UNKNOWN
};

class ScalarConverter
{
  public:
	static void convert(std::string str);
};
