/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:51:44 by jmigoya-          #+#    #+#             */
/*   Updated: 2024/04/28 15:57:38 by jmigoya-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void ScalarConverter::convert(std::string str)
{
	switch (_getType(str))
	{
	case CHAR:
		std::cout << "char" << std::endl;
		break;
	case INT:
		std::cout << "int" << std::endl;
		break;
	case FLOAT:
		std::cout << "float" << std::endl;
		break;
	case DOUBLE:
		std::cout << "double" << std::endl;
		break;
	case UNKNOWN:
		std::cout << "unknown" << std::endl;
		break;
	}
}

e_type ScalarConverter::_getType(std::string str)
{
	if (_isChar(str))
	{
		return CHAR;
	}
	else if (_isInt(str))
	{
		return INT;
	}
	else if (_isFloat(str))
	{
		return FLOAT;
	}
	else if (_isDouble(str))
	{
		return DOUBLE;
	}
	return UNKNOWN;
}

bool ScalarConverter::_isChar(std::string str)
{
	if (str.length() > 1 || std::isalpha(str[0]) == 0)
		return false;
	return true;
}

bool ScalarConverter::_isInt(std::string str)
{
	for (std::string::iterator it = str.begin(); it != str.end(); ++it)
		if (std::isdigit(*it) == 0)
			return false;
	return true;
}

bool ScalarConverter::_isFloat(std::string str)
{
	if (str.compare("-inff") == 0 || str.compare("+inff") == 0 ||
		str.compare("nanf") == 0)
		return true;

	if (std::count(str.begin(), str.end(), '.') != 1 ||
		std::count(str.begin(), str.end(), 'f') != 1)
		return false;

	for (std::string::iterator it = str.begin(); it != str.end(); ++it)
		if (std::isdigit(*it) == 0 && *it != '.' && *it != 'f')
			return false;
	return true;
}

bool ScalarConverter::_isDouble(std::string str)
{
	if (str.compare("-inf") == 0 || str.compare("+inf") == 0 ||
		str.compare("nan") == 0)
		return true;

	if (std::count(str.begin(), str.end(), '.') != 1)
		return false;

	for (std::string::iterator it = str.begin(); it != str.end(); ++it)
		if (std::isdigit(*it) == 0 && *it != '.')
			return false;
	return true;
}
