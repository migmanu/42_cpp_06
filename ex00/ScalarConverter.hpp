/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:51:36 by jmigoya-          #+#    #+#             */
/*   Updated: 2024/04/30 15:31:31 by jmigoya-         ###   ########.fr       */
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
	static e_type _type;
	static char _asChar;
	static int _asInt;
	static float _asFloat;
	static double _asDouble;

	static bool _isChar(std::string str);
	static bool _isInt(std::string str);
	static bool _isFloat(std::string str);
	static bool _isDouble(std::string str);

	void _getType(std::string str);

	static char _toChar(std::string str);
	static int _toInt(std::string str);
	static float _toFloat(std::string str);
	static double _toDouble(std::string str);

	void _printChar(std::string str);
	void _printInt(std::string str);
	void _printFloat(std::string str);
	void _printDouble(std::string str);

	ScalarConverter(void);
	ScalarConverter(const ScalarConverter &src);
	~ScalarConverter(void);

	ScalarConverter &operator=(const ScalarConverter &rhs);
};
