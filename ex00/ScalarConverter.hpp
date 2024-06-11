/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:51:36 by jmigoya-          #+#    #+#             */
/*   Updated: 2024/06/11 12:56:19 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

#define FLT_PRECISION  8
#define DBL_PRECISION  16

enum e_type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	UNKNOWN
};

class ScalarConverter
{
  public:
	static void convert(std::string str);

  private:
	ScalarConverter(void);
};
