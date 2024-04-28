/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:51:36 by jmigoya-          #+#    #+#             */
/*   Updated: 2024/04/28 15:53:21 by jmigoya-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <variant>
#include <algorithm>

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
	static bool _isChar(std::string str);
	static bool _isInt(std::string str);
	static bool _isFloat(std::string str);
	static bool _isDouble(std::string str);

	static e_type _getType(std::string str);

	void _printChar(std::string str);
	void _printInt(std::string str);
	void _printFloat(std::string str);
	void _printDouble(std::string str);

	ScalarConverter(void);
	ScalarConverter(const ScalarConverter &src);
	~ScalarConverter(void);

	ScalarConverter &operator=(const ScalarConverter &rhs);
};
