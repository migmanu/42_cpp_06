/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:51:44 by jmigoya-          #+#    #+#             */
/*   Updated: 2024/04/30 15:34:46 by jmigoya-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void ScalarConverter::convert(std::string str)
{
	switch (_type)
	{
	case CHAR: {
		std::cout << "Inputed literal is type character." << std::endl << std::endl;
		_asChar = _toChar(str);
		break;
	}
	case INT: {
		std::cout << "Inputed literal is type integer." << std::endl << std::endl;
		_asInt = _toInt(str);
		break;
	}
	case FLOAT: {
		std::cout << "Inputed literal is type float." << std::endl << std::endl;
		_asFloat = _toFloat(str);
		break;
	}
	case DOUBLE: {
		std::cout << "Inputed literal is type double." << std::endl << std::endl;
		_asDouble = _toDouble(str);
		break;
	}
	case UNKNOWN: {
		std::cout << "Inputed literal is type unknown." << std::endl << std::endl;
		break;
	}
	}
}

void ScalarConverter::_getType(std::string str)
{
	if (_isChar(str))
	{
		_type = CHAR;
	}
	else if (_isInt(str))
	{
		_type = INT;
	}
	else if (_isFloat(str))
	{
		_type = FLOAT;
	}
	else if (_isDouble(str))
	{
		_type = DOUBLE;
	}
	_type = UNKNOWN;
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

char ScalarConverter::_toChar(std::string str)
{
	return str[0];
}

int ScalarConverter::_toInt(std::string str)
{
	return std::atoi(str.c_str());
}

float ScalarConverter::_toFloat(std::string str)
{
	return std::atof(str.c_str());
}

double ScalarConverter::_toDouble(std::string str)
{
	return std::atof(str.c_str());
}
